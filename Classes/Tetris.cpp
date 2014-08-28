//
//  Tetris.cpp
//  projectTetris
//
//  Created by huagc on 2014/06/06.
//
//

#include "Tetris.h"

Tetris::Tetris()
{
    init();
}

void Tetris::init()
{
    difficultx=25;
    Next=100;
    TheWorld.clear();
    dynamicTetris.clear();
    score=0;
    
    for(int i=0;i<30;i++)
    {
        TheWorld.push_back(0b1100000000000011);
    }
    
    TheWorld.push_back(0b1111111111111111);
    TheWorld.push_back(0b1111111111111111);
    
    cout<<"the world"<<TheWorld.size()<<endl;
    
    
    TetrisStrctures[0][0][0]=0b0000001111000000;
    TetrisStrctures[0][1][0]=0b0000000100000000;
    TetrisStrctures[0][1][1]=0b0000000100000000;
    TetrisStrctures[0][1][2]=0b0000000100000000;
    TetrisStrctures[0][1][3]=0b0000000100000000;
    TetrisStrctures[1][0][0]=0b0000001110000000;
    TetrisStrctures[1][0][1]=0b0000000100000000;
    TetrisStrctures[1][3][0]=0b0000000010000000;
    TetrisStrctures[1][3][1]=0b0000000110000000;
    TetrisStrctures[1][3][2]=0b0000000010000000;
    TetrisStrctures[1][2][0]=0b0000000100000000;
    TetrisStrctures[1][2][1]=0b0000001110000000;
    TetrisStrctures[1][1][0]=0b0000001000000000;
    TetrisStrctures[1][1][1]=0b0000001100000000;
    TetrisStrctures[1][1][2]=0b0000001000000000;
    TetrisStrctures[2][0][0]=0b0000000110000000;
    TetrisStrctures[2][0][1]=0b0000000110000000;
    TetrisStrctures[3][0][0]=0b0000000010000000;
    TetrisStrctures[3][0][1]=0b0000000110000000;
    TetrisStrctures[3][0][2]=0b0000000100000000;
    TetrisStrctures[3][1][0]=0b0000001100000000;
    TetrisStrctures[3][1][1]=0b0000000110000000;
    TetrisStrctures[4][0][0]=0b0000000100000000;
    TetrisStrctures[4][0][1]=0b0000000110000000;
    TetrisStrctures[4][0][2]=0b0000000010000000;
    TetrisStrctures[4][1][0]=0b0000000110000000;
    TetrisStrctures[4][1][1]=0b0000001100000000;
    TetrisStrctures[5][0][0]=0b0000000110000000;
    TetrisStrctures[5][0][1]=0b0000000010000000;
    TetrisStrctures[5][0][2]=0b0000000010000000;
    TetrisStrctures[5][3][0]=0b0000000001000000;
    TetrisStrctures[5][3][1]=0b0000000111000000;
    TetrisStrctures[5][2][0]=0b0000000100000000;
    TetrisStrctures[5][2][1]=0b0000000100000000;
    TetrisStrctures[5][2][2]=0b0000000110000000;
    TetrisStrctures[5][1][0]=0b0000000111000000;
    TetrisStrctures[5][1][1]=0b0000000100000000;
    TetrisStrctures[6][0][0]=0b0000000110000000;
    TetrisStrctures[6][0][1]=0b0000000100000000;
    TetrisStrctures[6][0][2]=0b0000000100000000;
    TetrisStrctures[6][3][0]=0b0000000111000000;
    TetrisStrctures[6][3][1]=0b0000000001000000;
    TetrisStrctures[6][2][0]=0b0000000010000000;
    TetrisStrctures[6][2][1]=0b0000000010000000;
    TetrisStrctures[6][2][2]=0b0000000110000000;
    TetrisStrctures[6][1][0]=0b0000000100000000;
    TetrisStrctures[6][1][1]=0b0000000111000000;
    
    insertTetris();
}

void Tetris::insertTetris()
{
    if(Next==100)
    {
        Next=(int)(arc4random() % 7);
    }
    int Ttype2=(int)(arc4random() % TetrisStrctures[Next].size());
    for(int i=0;i<32;i++)
    {
        dynamicTetris.push_back(0b0);
    }
    dynamicY=0;
    dynamicX=0;
    dynamicStatus=make_pair(Next,Ttype2);
    
    for(int i=0;i<TetrisStrctures[Next][Ttype2].size();i++)
    {
        dynamicTetris[i]|=TetrisStrctures[Next][Ttype2][i];
    }
    
    Next=(int)(arc4random() % 7);
    hasDynamic=true;
}

bool Tetris::update(vector<unsigned short>& TheWorldToPrint,vector<unsigned short>& dynamicTetrisToPrint,int action,int& score,vector<unsigned short>& NextStructure,int difficult)
{
    if(difficultx!=difficult)
    {
        init();
        difficultx=difficult;
        return true;
    }
    static int kk=0;
    
    NextStructure.clear();
    
    for(int i=0;i<32;i++)
    {
        NextStructure.push_back(0b0);
    }
    
    for(int i=0;i<TetrisStrctures[Next][0].size();i++)
    {
        unsigned short tmp=TetrisStrctures[Next][0][i];
        NextStructure[i]|=tmp;
    }
    
    
    if(action<=3)
    {
        calculateNextDynamicTetris(action);
        if(Ifmoveable(NextBlock))
        {
            dynamicTetris=NextBlock;
            switch (action) {
                case 0:
                    dynamicY++;
                    break;
                case 1:
                    
                    dynamicX++;
                    break;
                case 2:
                    
                    dynamicX--;
                    break;
                case 3:
                    
                    if(TetrisStrctures[dynamicStatus.first].find(dynamicStatus.second+1)!=TetrisStrctures[dynamicStatus.first].end())
                    {
                        dynamicStatus.second++;
                    }
                    else
                    {
                        dynamicStatus.second=0;
                    }
                    break;
                    
                    
                default:
                    break;
            }
        }
        else if(action==3)
        {
            bool get=false;
            vector<unsigned short> tmpBlock;
            tmpBlock=NextBlock;
            

            for(int i=0;i<32;i++)
            {
                tmpBlock[i]=NextBlock[i]<<1;
            }
            if(Ifmoveable(tmpBlock))
            {
                dynamicTetris=tmpBlock;
                dynamicX--;
                get=true;
                cout<<"xxx"<<endl;
            }
            
            if (!get)
            {
                for(int i=0;i<32;i++)
                {
                    tmpBlock[i]=NextBlock[i]<<2;
                }
                if(Ifmoveable(tmpBlock))
                {
                    dynamicTetris=tmpBlock;
                    dynamicX-=2;
                    get=true;
                    cout<<"aaa"<<endl;
                }
            }
            
            if (!get)
            {
                for(int i=0;i<32;i++)
                {
                    tmpBlock[i]=NextBlock[i]>>1;
                }
                if(Ifmoveable(tmpBlock))
                {
                    dynamicTetris=tmpBlock;
                    dynamicX++;
                    get=true;
                    cout<<"yyy"<<endl;
                }
            }
            
            if (!get)
            {
                for(int i=0;i<32;i++)
                {
                    tmpBlock[i]=NextBlock[i]>>2;
                }
                if(Ifmoveable(tmpBlock))
                {
                    dynamicTetris=tmpBlock;
                    dynamicX+=2;
                    get=true;
                    cout<<"KKK"<<endl;
                }
            }
            
            if(get)
            {
                if(TetrisStrctures[dynamicStatus.first].find(dynamicStatus.second+1)!=TetrisStrctures[dynamicStatus.first].end())
                {
                    dynamicStatus.second++;
                }
                else
                {
                    dynamicStatus.second=0;
                }
            }
        }
        
        else if(action==0)
        {
            merge(dynamicTetris);
            score=checkscore();
            insertTetris();
            calculateNextDynamicTetris(0);
            if(!Ifmoveable(NextBlock)) return false;
        }
    }
    if(kk++>=((10-difficultx)*5))
    {
        kk=0;
        action=0;
        
        calculateNextDynamicTetris(action);
        if(Ifmoveable(NextBlock))
        {
            dynamicTetris=NextBlock;
            dynamicY++;
        }
        else
        {
            merge(dynamicTetris);
            insertTetris();
            score=checkscore();
            calculateNextDynamicTetris(0);
            if(!Ifmoveable(NextBlock)) return false;
        }
    }
    TheWorldToPrint=TheWorld;
    dynamicTetrisToPrint=dynamicTetris;
    return true;
}

void Tetris::calculateNextDynamicTetris(int action)
{
    NextBlock.clear();
    
    for(int i=0;i<32;i++)
    {
        NextBlock.push_back(0b0);
    }
    
    
    int number=0;
    
    switch (action) {
        case 0:
            
            for(int i=0;i<TetrisStrctures[dynamicStatus.first][dynamicStatus.second].size();i++)
            {
                unsigned short tmp=TetrisStrctures[dynamicStatus.first][dynamicStatus.second][i];
                if(dynamicX>=0)
                    tmp=tmp>>(abs(dynamicX));
                else
                    tmp=tmp<<(abs(dynamicX));
                NextBlock[i+dynamicY+1]|=tmp;
            }
            break;
        case 1:
            
            for(int i=0;i<TetrisStrctures[dynamicStatus.first][dynamicStatus.second].size();i++)
            {
                unsigned short tmp=TetrisStrctures[dynamicStatus.first][dynamicStatus.second][i];
                if(dynamicX+1<0)
                    tmp=tmp<<(abs(dynamicX)-1);
                else
                    tmp=tmp>>(dynamicX+1);
                NextBlock[i+dynamicY]|=tmp;
            }
            break;
        case 2:
            
            for(int i=0;i<TetrisStrctures[dynamicStatus.first][dynamicStatus.second].size();i++)
            {
                unsigned short tmp=TetrisStrctures[dynamicStatus.first][dynamicStatus.second][i];
                if(dynamicX-1>=0)
                    tmp=tmp>>(abs(dynamicX)-1);
                else
                    tmp=tmp<<(abs(dynamicX)+1);
                NextBlock[i+dynamicY]|=tmp;
            }
            break;
            
            
        case 3:
            if(TetrisStrctures[dynamicStatus.first].find(dynamicStatus.second+1)!=TetrisStrctures[dynamicStatus.first].end())
            {
                number=dynamicStatus.second+1;
            }
            
            for(int i=0;i<TetrisStrctures[dynamicStatus.first][number].size();i++)
            {
                unsigned short tmp=TetrisStrctures[dynamicStatus.first][number][i];
                if(dynamicX>=0)
                    tmp=tmp>>(abs(dynamicX));
                else
                    tmp=tmp<<(abs(dynamicX));
                NextBlock[i+dynamicY]|=tmp;
            }
            break;
            
            
        default:
            break;
    }
}

bool Tetris::Ifmoveable(vector<unsigned short>& dynamicblocks)
{
    for(int i=0;i<32;i++)
    {
        if((TheWorld[i]&dynamicblocks[i])!=0)
        {
            return false;
        }
    }
    return true;
}

void Tetris::merge(vector<unsigned short>& dynamicblocks)
{
    for(int i=0;i<32;i++)
    {
        TheWorld[i]=TheWorld[i]|dynamicblocks[i];
    }
}

int Tetris::checkscore()
{
    int scorex=0;
    for(int i=0;i<=29;i++)
    {
        if(TheWorld[i]==0b1111111111111111)
        {
            scorex++;
            for(int j=i;j>=1;j--)
            {
                TheWorld[j]=TheWorld[j-1];
            }
            TheWorld[0]=0b1100000000000011;
        }
    }
    scorex*=scorex;
    score+=scorex;
    return score;
}


