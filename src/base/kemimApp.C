#include "kemimApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
kemimApp::validParams()
{
  InputParameters params = MooseApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

kemimApp::kemimApp(InputParameters parameters) : MooseApp(parameters)
{
  kemimApp::registerAll(_factory, _action_factory, _syntax);
}

kemimApp::~kemimApp() {}

void
kemimApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAllObjects<kemimApp>(f, af, syntax);
  Registry::registerObjectsTo(f, {"kemimApp"});
  Registry::registerActionsTo(af, {"kemimApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
kemimApp::registerApps()
{
  registerApp(kemimApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
kemimApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  kemimApp::registerAll(f, af, s);
}
extern "C" void
kemimApp__registerApps()
{
  kemimApp::registerApps();
}
