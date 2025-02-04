/*
	coordinate_frame.h
	
	Based on the class provided at this link:
	https://www.gamasutra.com/view/feature/131761/c_data_structures_for_rigidbody_.php?page=5
	C++ Data Structures for Rigid-Body Physics: The COORDINATE_FRAME Type
	Author: Miguel Gomez
	02/07/99

	@author	Miguel Gomez, Josh Hale
	Last Edited: 02/12/17
*/

#ifndef _COORDINATE_FRAME_H
#define _COORDINATE_FRAME_H

#include "basis.h"

namespace obb
{
	class CoordinateFrame : public Basis
	{
		public:
			Point O;	//this coordinate frame�s origin, relative to its parent frame

		public:
			CoordinateFrame() {}
			CoordinateFrame(const Point& o, const Vector& v0, const Vector& v1, const Vector& v2)
				: O(o), Basis(v0, v1, v2) {}

			CoordinateFrame(const Point& o, const Basis& b) : O(o), Basis(b) {}
			
			const void SetCoordinateFrame(const Point& o, const Vector& v0, const Vector& v1, const Vector& v2)
			{
				O = o;
				SetBasis(v0, v1, v2);
			}

			const Point& position() const { return O; }
			void position(const Point& p) { O = p; }
			const Point transformPointToLocal(const Point& p) const
			{
				//translate to this frame�s origin, then project onto this basis
				return transformVectorToLocal(p - O);
			}

			const Point transformPointToParent(const Point& p) const
			{
				//transform the coordinate vector and translate by this origin
				return transformVectorToParent(p) + O;
			}

			//translate the origin by the given vector
			void translate(const Vector& v)
			{
				O += v;
			}
	};
}
#endif //_COORDINATE_FRAME_H
