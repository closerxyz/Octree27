#ifndef TransitionPatternVisitor_h
#define TransitionPatternVisitor_h 1

#include "../OctreeEdge.h"
#include "../MeshPoint.h"
#include "../TriMesh.h"

#include "../TransitionTemplate.h"

//#include "../SurfTemplate1.h"
//#include "../SurfTemplate2.h"
//#include "../SurfTemplate3.h"
//#include "../SurfTemplate4.h"
//#include "../SurfTemplate5.h"
//#include "../SurfTemplate6.h"
//#include "../SurfTemplate7.h"
//#include "../SurfPrism.h"
//#include "../SurfPyramid.h"
//#include "../SurfTetrahedron.h"
//#include "../SurfHexahedron.h"

#include "Visitor.h"
#include "EdgeVisitor.h"

#include <list>
#include <set>
#include <vector>

using Clobscode::MeshPoint;
using Clobscode::OctreeEdge;
using Clobscode::TriMesh;
using std::list;
using std::set;
using std::vector;

namespace Clobscode {
   class TransitionPatternVisitor : public Visitor{
   public:
      TransitionPatternVisitor();
      TransitionPatternVisitor(bool apply_pattern);

      bool visit(Octant *o);

      void setPoints(vector<MeshPoint> &points);
      void setNewPoints(list<Point3D> &new_pts);
      void setEdges(const set<OctreeEdge> &edges);
      void setMaxRefLevel(const unsigned short &max_ref_level);
      void setApplyMode(bool apply_pattern);
      void setVNodes(set<unsigned long> &v_nodes);
      void setPuntosExtras(vector<Point3D> &puntosVector, vector<unsigned long> &idxsVector, set<unsigned long> &idxsRefinados);

      void setToRefineList(vector<vector<unsigned long>>& to_refine) { edges_to_refine = &to_refine; };
      void setAssociationTable(string table_name) { assoc_table_name = table_name; };

   private:
      vector<MeshPoint> *points;
      list<Point3D> *new_pts;
      const set<OctreeEdge> *edges;
      const unsigned short *max_ref_level;
      bool apply_pattern;
      set<unsigned long> *v_nodes;

      vector<Point3D> *puntosVector;
      vector<unsigned long> *idxsVector;
      set<unsigned long> *idxsRefinados;

      vector<vector<unsigned long>>* edges_to_refine;
      string assoc_table_name;
   };
}

#endif //MESHER_ROI_TRANSITIONPATTERNVISITOR_H
