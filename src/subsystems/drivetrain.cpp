#include "main.h"

using namespace okapi;

std::shared_ptr<ChassisController> drive =
  ChassisControllerBuilder()
  .withMotors({leftBackDrive, leftFrontDrive}, {rightFrontDrive, rightBackDrive}) 												//MotorGroups for left and right side
  .withDimensions(AbstractMotor::gearset::blue, {{4_in, 10_in}, imev5BlueTPR})		  //Gearset(rpm) and wheel dimensions
  .build();

void joystickDrive()
{
  drive -> getModel() -> arcade(controller.getAnalog(ControllerAnalog::leftY),
                                controller.getAnalog(ControllerAnalog::rightX));
}
