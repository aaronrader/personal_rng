#pragma once
#include <random>
#define RAND_FLOAT ((double)rand()/(double)RAND_MAX)

template<typename T>
T rando(const T& min, const T& max) {
	return (T)(RAND_FLOAT * ((T)max - min) + min);
}