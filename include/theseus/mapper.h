/*	DESCRIPTION:
*	This is the header for the mapper class.
*
*/
#ifndef MAPPER_H
#define MAPPER_H

#include <vector>
#include <algorithm>
#include <math.h>
#include <stdlib.h>

#include <theseus/map_s.h>
#include <theseus/gps_struct.h>
#include <theseus/rand_gen.h>
#include <theseus/param_reader.h>

namespace theseus
{
class mapper
{
public:
	// Functions
  mapper();
	mapper(unsigned int seed, ParamReader *input_file);		// default constructor (uses the competition boundaries) with random obstacles.
	~mapper();
  void translateBoundaries(double lat, double lon, double height);

	// Members
	map_s map; // The map struct. This is where all of the important information about the created map.

private:
	// Functions
	bool flyZoneCheckMASTER(const NED_s, double radius);  // This is the main flyZoneCheck for the mapper class.
	bool flyZoneCheck(const cyl_s cyl);                   // Return false if the cylinder intersect with other obstacles - calls flyZoneCheckMASTER()
	bool flyZoneCheck(const NED_s NED, double radius);    // Return false if the point gets within radius of an obstacle - calls flyZoneCheckMASTER()
	void tempGPS_converter(double lat, double lon, double h);
  // Members
	ParamReader *input_file;                        // Input Parameters File Variables
	RandGen rg;                                     // This is the random generator
	std::vector<std::vector<double> > lineMinMax;   // (N x 4) vector containing the (min N, max N, min E, max E) for each boundary line
	std::vector<std::vector<double> > line_Mandb;   // (N x 4) vector that contains the slope and intercept of the line (m, b, (-1/m), (m + 1/m)) from N = m*E + b ... not sure about E = constant lines yet.
	unsigned int nBPts;                             // Number of Boundary Points
	unsigned int nCyli;                             // Number of Cylinder Obstacles
	double maxNorth;                                // Calculated maximum North Coordinate within boundaries
	double minNorth;                                // Calculated minimum North Coordinate within boundaries
	double maxEast;                                 // Calculated maximum East  Coordinate within boundaries
	double minEast;                                 // Calculated minimum East  Coordinate within boundaries
	double minFlyHeight;                            // Floor of fly zone
	double maxFlyHeight;                            // Ceiling of fly zone
	double minCylRadius;                            // Minimum Cylinder Radius in meters
	double maxCylRadius;                            // Maximum Cylinder Radius in meters
	double minCylHeight;                            // Minimum Cylinder Height in meters
	double maxCylHeight;                            // Maximum Cylinder Height in meters
	double waypoint_clearance;                      // The radius away from any obstacle that the waypoints are placed
	bool   is3D;                                    // If true, the board is 3D (cylinders have height) if false board is 2D (cylinders have height = to maxFlyHeight)
  double rPhi_;
  double rLam_;
  double rH_;
};
}
#endif
