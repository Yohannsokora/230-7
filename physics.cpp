/***********************************************************************
 * Source File:
 *    PHYSICS
 * Author:
 *    <your name here>
 * Summary:
 *    Laws of motion, effects of gravity, wind resistence, etc.
 ************************************************************************/
  
 #include "physics.h"  // for the prototypes
 
 /*********************************************************
 * LINEAR INTERPOLATION
 * From a list of domains and ranges, linear interpolate
 *********************************************************/
double linearInterpolation(const Mapping mapping[], int numMapping, double domain)
{
   for (int i = 0; i < numMapping - 1; ++i){
      if (domain >= mapping[i].domain && domain <= mapping[i + 1].domain){
         return linearInterpolation(mapping[i].domain, mapping[i].range,
         mapping[i + 1].domain, mapping[i + 1].range, domain);
      }
   }
   return -1.0;
}

/*********************************************************
 * GRAVITY FROM ALTITUDE
 * Determine gravity coefficient based on the altitude
 *********************************************************/
double gravityFromAltitude(double altitude)
{
   Mapping gravityMapping[] = {
      {0.0, 9.807},
      {10000.0, 9.776},
      {80000.0, 9.564}
   };
   return linearInterpolation(gravityMapping, 3, altitude);
}

/*********************************************************
 * DENSITY FROM ALTITUDE
 * Determine the density of air based on the altitude
 *********************************************************/
double densityFromAltitude(double altitude)
{
   Mapping densityMapping[] = {
      {0.0, 1.225},
      {10000.0, 0.4135000},
      {80000.0, 0.0000185}
   };
   return linearInterpolation(densityMapping, 3, altitude);
}

/*********************************************************
 * SPEED OF SOUND FROM ALTITUDE
 * determine the speed of sound for a given altitude.
 ********************************************************/
double speedSoundFromAltitude(double altitude)
{
   Mapping speedSoundMapping[] = {
      {0.0, 340.0},
      {10000.0, 299.0},
      {80000.0, 269.0}
   };
   return linearInterpolation(speedSoundMapping, 3, altitude);
}


/*********************************************************
 * DRAG FROM MACH
 * Determine the drag coefficient for a M795 shell given speed in Mach
 *********************************************************/
double dragFromMach(double speedMach)
{
   Mapping dragMapping[] = {
      {0.0, 0.0},
      {1.0, 0.4258},
      {5.0, 0.2656}
   };
   return linearInterpolation(dragMapping, 3, speedMach);
}

