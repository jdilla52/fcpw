#pragma once

#include "sbvh.h"

namespace fcpw {

template <int DIM>
class Qbvh: public Aggregate<DIM> {
public:
	// constructor
	Qbvh(const std::shared_ptr<Sbvh<DIM>>& sbvh_);

	// returns bounding box
	BoundingBox<DIM> boundingBox() const;

	// returns centroid
	Vector<DIM> centroid() const;

	// returns surface area
	float surfaceArea() const;

	// returns signed volume
	float signedVolume() const;

	// intersects with ray
	int intersect(Ray<DIM>& r, std::vector<Interaction<DIM>>& is,
				  bool checkOcclusion=false, bool countHits=false) const;

	// finds closest point to sphere center
	bool findClosestPoint(BoundingSphere<DIM>& s, Interaction<DIM>& i) const;
};

} // namespace fcpw

#include "qbvh.inl"