#ifndef ADJACENT_MATRIX_H_
#define ADJACENT_MATRIX_H_

#include <vector>
#include "dedge.h"
struct Link
{
	Link(){}
	Link(int _id, float _w = 1)
		: id(_id), weight(_w)
	{}
	inline bool operator<(const Link &link) const { return id < link.id; }
	int id;
	float weight;
};

struct TaggedLink {
	int id;
	unsigned char flag;
	TaggedLink(){}
	TaggedLink(int id) : id(id), flag(0) { }
	bool used() const { return flag & 1; }
	void markUsed() { flag |= 1; }
	TaggedLink& operator=(const Link& l) {
		flag = 0;
		id = l.id;
		return *this;
	}
};

typedef std::vector<std::vector<Link> > AdjacentMatrix;

void generate_adjacency_matrix_uniform(
	const MatrixXi &F, const VectorXi &V2E, const VectorXi &E2E,
	const VectorXi &nonManifold, AdjacentMatrix& adj);

#endif