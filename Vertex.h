/***************************************************************************
 *   Copyright (C) 2008 by    *
 *      *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
#ifndef __VERTEX_H_
#define __VERTEX_H_

#include "Face.h"
#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

class Face;

          class Vertex{
                private:
                        
                        int index;
                        bool mark;
						bool isInterest;
						vector<int> faces;
						set<int> adjacentVertices;
						
						int depth;
						double response;
						int numNeighbors;

                        
                public:
                        double v[3];
                        Vertex() {v[0] = v[1] = v[2] = 0; mark = false; depth = 0;isInterest = 0;}
                        Vertex(double x1, double y1, double z1) {v[0] = x1; v[1] = y1; v[2] = z1;mark = false; depth = 0;isInterest = 0;}
						
						double x() const { return v[ 0 ]; }
						double y() const { return v[ 1 ]; }
						double z() const { return v[ 2 ]; }

						double& x() { return v[ 0 ]; }
						double& y() { return v[ 1 ]; }
						double& z() { return v[ 2 ]; }
						
						double getX() {return v[0];}
						double getY() {return v[1];}
						double getZ() {return v[2];}
						
						void setX(double x1) {v[0] = x1;}
						void setY(double y1) {v[1] = y1;}
						void setZ(double z1) {v[2] = z1;}

						bool operator==(const Vertex& p) const
						{
							return (x() == p.x()) && (y() == p.y()) && (z() == p.z())  ;
						}

						bool  operator!=(const Vertex& p) const { return ! (*this == p); }
						
						friend ostream& operator<<(ostream& out, Vertex& point);

                        void setVertex(double x1, double y1, double z1){v[0] = x1; v[1] = y1; v[2] = z1;}
                        void setIndex(int ind){index = ind;}
                        int getIndex(){return index;}
                        
						bool isMarked(){return mark;}
                        void setMark(bool mark1){mark = mark1;}
						int getDepth(){ return depth;}
						void setDepth(int dep){ depth = dep;}
						double getResponse(){return response;}
						void setResponse(double resp){response = resp;}
						bool getInterest(){return isInterest;}
                        
                        void getNeighborhood(int rad, vector<Vertex*>& V, Vertex* vertices);
						int getRadius(Vertex* vertices, double radius, vector<Vertex*>& V);
						
						
						void addVertex(int vertex){ adjacentVertices.insert(vertex);}
						void addFace(int face){ faces.push_back(face); }
						void processMaximum(Vertex* vertices, int numRings);
						vector<int>& getFaces(){ return faces;}
						set<int>& getAdjacentVertices() { return adjacentVertices;}
						
		};

#endif
