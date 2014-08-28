//
//  Tetris.h
//  projectTetris
//
//  Created by huagc on 2014/06/06.
//
//

#ifndef __projectTetris__Tetris__
#define __projectTetris__Tetris__

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Tetris
{
    void insertTetris();
    vector<unsigned short> TheWorld;
    vector<unsigned short> dynamicTetris;
    bool hasDynamic;
    bool Ifmoveable(vector<unsigned short>& dynamicblocks);
    int dynamicX,dynamicY;
    pair<int,int> dynamicStatus;
    map<int, map <int, map<int,unsigned short> > > TetrisStrctures;
    void calculateNextDynamicTetris(int action=0);
    vector<unsigned short> NextBlock;
    void merge(vector<unsigned short>& dynamicblocks);
    int checkscore();
    int score;
    int Next;
    int difficultx;
    
    
public:
    bool update(vector<unsigned short>& TheWorldToPrint,vector<unsigned short>& dynamicTetrisToPrint,int action,int& score,vector<unsigned short>& NextStructure,int difficult);
    Tetris();
    
    void init();
};

#endif /* defined(__projectTetris__Tetris__) */
