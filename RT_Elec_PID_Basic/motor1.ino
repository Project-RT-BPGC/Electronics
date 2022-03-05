//double kp1=2, ki1=5, kd1=1;


double motor1(double Input1)
{
  PID myPID(&Input1, &Output1, &Setpoint1, kp1, ki1, kd1, DIRECT);
  myPID.SetMode(AUTOMATIC);
  myPID.Compute();
  return Output1;
}
