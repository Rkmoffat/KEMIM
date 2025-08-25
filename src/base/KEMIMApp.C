#include "KEMIMApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
KEMIMApp::validParams()
{
  InputParameters params = MooseApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

KEMIMApp::KEMIMApp(InputParameters parameters) : MooseApp(parameters)
{
  KEMIMApp::registerAll(_factory, _action_factory, _syntax);
}

KEMIMApp::~KEMIMApp() {}

void
KEMIMApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAllObjects<KEMIMApp>(f, af, syntax);
  Registry::registerObjectsTo(f, {"KEMIMApp"});
  Registry::registerActionsTo(af, {"KEMIMApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
KEMIMApp::registerApps()
{
  registerApp(KEMIMApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
KEMIMApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  KEMIMApp::registerAll(f, af, s);
}
extern "C" void
KEMIMApp__registerApps()
{
  KEMIMApp::registerApps();
}
