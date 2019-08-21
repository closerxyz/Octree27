/*
 * PatternsDefault.h
 *
 *  Created on: May 18, 2012
 *      Author: jsepulve
 */

#include <iostream>
#include <vector>
#include <map>
#include <bitset>
#include "TransitionCube.h"


#ifndef PATTERN_FACTORY_H_
#define PATTERN_FACTORY_H_

using std::vector;
using std::map;
using std::bitset;
using std::cout;

namespace patterns {

typedef unsigned long Uint;
typedef vector< vector<Uint> > VTable;
typedef vector< vector<Uint> >::iterator VTableIter;

static const Uint TETRA_POINTS  =4;
static const Uint PYRAMID_POINTS=5;
static const Uint PRISM_POINTS  =6;
static const Uint HEXA_POINTS   =8;
static const Uint CORNER_POINTS =8;
static const Uint EDGE_POINTS   =24;
static const Uint FACE_POINTS   =24;
static const Uint TOTAL_POINTS  =64;
static const Uint PERMUTATIONS  =30;
//static const Uint MAX_ELEMENTS  =71;
static const Uint MAX_ELEMENTS  =82;
static const Uint NUM_PATTERNS  =26;


class PatternFactory {
public:
    
    // Struct to contain points and size of one element.
    struct item {
        Uint size;
        Uint points[CORNER_POINTS];
    };

/* OLD * /
    // Struct contains one element and the mask its edge point associated.
    struct Element {
        Uint mask;
        item items[MAX_ELEMENTS];
    };
/* /OLD */

    /// NEW; templates definition (T2, T3, T4, T40, etc...)
    struct Template_st{
       Uint id; // necessary?
       item items[MAX_ELEMENTS];
    };

    /// NEW; Pattern table entry (pattern -> template)
    struct PatternTemplateMap{ // TODO encontrar mejor nombre =P
       /// pattern mask (same as mask of Element struct)
       Uint mask;
       /// Index of template (In array of templates def.)
       Uint template_ix; // or use? Uint template_id; ??
    };

    static PatternFactory *instance();
    static void deleteInstance();

    //virtual void createPattern(vector< vector<Uint> > & p);
    bool createPattern(Uint);

    void vectors(vector< vector<Uint> > & p ) { p = pattern; };
private:
    PatternFactory() { };

    virtual ~PatternFactory() { };
    PatternFactory(const PatternFactory &) { };
    PatternFactory& operator=(PatternFactory const&){ return *this; };

    //static const Element elements[]; //OLD
    static const Template_st templates[];
    static const PatternTemplateMap pattern_table[];

    static PatternFactory* m_Instance;
    static int m_NumInstances;

    vector< vector<Uint> > pattern;

};

}

#endif /* PATTERN_FACTORY_H_ */
