FMUs = \
AircraftVehicleDemonstrator.Atmosphere_Model_FMU_sf \
AircraftVehicleDemonstrator.bC \
AircraftVehicleDemonstrator.cockpit \
AircraftVehicleDemonstrator.consumer_A \
AircraftVehicleDemonstrator.consumer_B \
AircraftVehicleDemonstrator.eCS_Generic_Export \
AircraftVehicleDemonstrator.eCS_SW \
AircraftVehicleDemonstrator.engine \
ASSCExample.Class1 \
ASSCExample.Class2 \
DualMassOscillator.System1 \
DualMassOscillator.System2 \
HelloWorld \
HelloWorldWithInput \
Lin2DimODE \
Modelica.Blocks.Continuous.Integrator \
Modelica.Blocks.Math.Add \
Modelica.Blocks.Math.Add3 \
Modelica.Blocks.Math.Feedback \
Modelica.Blocks.Math.Gain \
Modelica.Blocks.Math.Product \
Modelica.Blocks.Nonlinear.Limiter \
Modelica.Blocks.Sources.Clock \
Modelica.Blocks.Sources.Constant \
Modelica.Blocks.Sources.Sine \
Modelica.Blocks.Sources.Step \
QuarterCarModel.DisplacementDisplacement.Chassis \
QuarterCarModel.DisplacementDisplacement.Wheel \
QuarterCarModel.DisplacementForce.Chassis \
QuarterCarModel.DisplacementForce.Wheel \
tlm.adder \
tlm.CoarseGrained1_1D \
tlm.CoarseGrained2_1D \
tlm.FineGrained1_1D \
tlm.FineGrained2_1D \
tlm.gain \
tlm.LowerPendulum \
tlm.LowerPendulumFG \
tlm.mass \
tlm.massSpring \
tlm.source \
tlm.UpperPendulum \
tlm.UpperPendulumFG \
tlm.UpperPendulumFG \

MOSs = \
ASSCExample.mos \
DualMassOscillator.mos \
HelloWorldWithInput.mos \
Mass.mos \
QuarterCarModel.mos \
Blocks.mos \
HelloWorld.mos \
Lin2DimODE.mos \
MassSpring.mos \

.PHONY: all generateFMUs

all:
	@echo
	@echo preparing FMUs...
	@for fmu in $(FMUs) ; do cd $$fmu && zip -r ../$$fmu.fmu * && cd .. ; done

generateFMUs:
	@echo
	@echo generating FMUs...
	@for mos in $(MOSs) ; do omc $$mos ; done
