###############################################################################
################### MOOSE Application Standard Makefile #######################
###############################################################################
#
# Optional Environment variables
# MOOSE_DIR        - Root directory of the MOOSE project
#
###############################################################################
# Use the MOOSE submodule if it exists and MOOSE_DIR is not set
MOOSE_SUBMODULE    := $(CURDIR)/moose
ifneq ($(wildcard $(MOOSE_SUBMODULE)/framework/Makefile),)
  MOOSE_DIR        ?= $(MOOSE_SUBMODULE)
else
  MOOSE_DIR        ?= $(shell dirname `pwd`)/moose
endif

# framework
FRAMEWORK_DIR      := $(MOOSE_DIR)/framework
include $(FRAMEWORK_DIR)/build.mk
include $(FRAMEWORK_DIR)/moose.mk

################################## MODULES ####################################
# To use certain physics included with MOOSE, set variables below to
# yes as needed.  Or set ALL_MODULES to yes to turn on everything (overrides
# other set variables).

ALL_MODULES                 := yes

CHEMICAL_REACTIONS          := yes
CONTACT                     := yes
ELECTROMAGNETICS            := yes
EXTERNAL_PETSC_SOLVER       := yes
FLUID_PROPERTIES            := yes
FSI                         := yes
FUNCTIONAL_EXPANSION_TOOLS  := yes
GEOCHEMISTRY                := yes
HEAT_TRANSFER               := yes
LEVEL_SET                   := yes
MISC                        := yes
NAVIER_STOKES               := yes
OPTIMIZATION                := yes
PERIDYNAMICS                := yes
PHASE_FIELD                 := yes
POROUS_FLOW                 := yes
RAY_TRACING                 := yes
REACTOR                     := yes
RDG                         := yes
RICHARDS                    := yes
SOLID_MECHANICS             := yes
STOCHASTIC_TOOLS            := no 
THERMAL_HYDRAULICS          := yes
XFEM                        := yes

include $(MOOSE_DIR)/modules/modules.mk
###############################################################################

# dep apps
APPLICATION_DIR    := $(CURDIR)
APPLICATION_NAME   := kemim
BUILD_EXEC         := yes
GEN_REVISION       := no
include            $(FRAMEWORK_DIR)/app.mk

###############################################################################
# Additional special case targets should be added here
