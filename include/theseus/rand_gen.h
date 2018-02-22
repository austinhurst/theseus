#ifndef RANDGEN_H
#define RANDGEN_H

#include <vector>
#include <stdlib.h>

namespace theseus
{
class RandGen
{
public:
	RandGen(unsigned int seed_in);	// Use this contructor - give it a seed
	RandGen();						// Default contructor - NO SEED. Needed to allow randGen to be a member of a class
	~RandGen();						// Deconstructor
	double randLin();				// This public function returns a random number from 0 to 1, uniform distribution.
	std::vector<unsigned int> UINTv(unsigned int len);	// Returns a vector of length len of random unsigned integers
  unsigned int UINT();
private:
	unsigned int seed;				// Stores the seed - might be unnecessary.
};
}
#endif
