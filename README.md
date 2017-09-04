# Udacity CARND Term 2 Project 4 - PID Controller
## PID Parameter Definitions

The PID Controller uses three different paramters in order to control a system. Which in this case is a vehicle drving arround the track. The -P parameter is the *proportional* parameter. Thus, if, for argument sake, a vehicle needs to keep to the speed limit of 60 km/hour then the error term would be defined as the speed limit minus the *true* vehicle speed. This value is then multiplied by a *gain* value. The output from this equation could be used to control the throttle of the vehicle.

Depending on the size of the gain value the correction could either be aggressive (Large gain) or not at all (Small value for gain). It is fair to see at this stage that there is no *damping* value. This means that with a P controller the velocity will always oscillate about the mean, 60 in this case.

In order to implement finer control we can now add a term that differentiates the error. This means that when the rate of change of the error is large the correction would be more aggressive than an instance where the change is gradual. This parameter also has a *gain* associated to it in order control how it changes a parameter. This -D term is used to dampen the system from the oscillations created by the -P term.

Finally we can add the -I term. This is the integral of the error which means that all of the errors are summed. This value reduces large fluctuations but also has the disadvantage that the model takes a while return to a good state if large errors were obtained.

Below is a video showcasing the effect of these parameters:

