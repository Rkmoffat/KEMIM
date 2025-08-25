//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "KEMIMTestApp.h"
#include "KEMIMApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"

InputParameters
KEMIMTestApp::validParams()
{
  InputParameters params = KEMIMApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

KEMIMTestApp::KEMIMTestApp(InputParameters parameters) : MooseApp(parameters)
{
  KEMIMTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

KEMIMTestApp::~KEMIMTestApp() {}

void
KEMIMTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  KEMIMApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"KEMIMTestApp"});
    Registry::registerActionsTo(af, {"KEMIMTestApp"});
  }
}

void
KEMIMTestApp::registerApps()
{
  registerApp(KEMIMApp);
  registerApp(KEMIMTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
KEMIMTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  KEMIMTestApp::registerAll(f, af, s);
}
extern "C" void
KEMIMTestApp__registerApps()
{
  KEMIMTestApp::registerApps();
}
