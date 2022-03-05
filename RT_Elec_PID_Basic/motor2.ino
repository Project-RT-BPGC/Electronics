double motor2(double Input2)
{
  PID myPID(&Input2, &Output2, &Setpoint2, kp2, ki2, kd2, DIRECT);
  myPID.SetMode(AUTOMATIC);
  myPID.Compute();
  return Output2;
}
