//
// Created by Eric on 22/10/2022.
//

#ifndef SKIFREE_DECOMP_TYPES_H
#define SKIFREE_DECOMP_TYPES_H

#include <SDL.h>

typedef int BOOL;
typedef void* HDC;
typedef void* HWND;
typedef void* HGDIOBJ;
typedef unsigned long DWORD;
typedef char* LPCSTR;

#define TRUE 1
#define FALSE 0

typedef struct _RECT {
    long left;
    long top;
    long right;
    long bottom;
} RECT, *PRECT;

typedef struct
{
    HDC sheetDC;
    HDC sheetDC_1bpp;
    SDL_Texture* sheet;
    short sheetYOffset;
    short width;
    short height;
    short totalPixels;
} Sprite;

typedef struct PermObject {
    struct Actor* actor;
    Sprite* spritePtr;
    short spriteIdx;
    // 2 bytes padding
    int actorTypeMaybe;
    int actorFrameNo;
    short maybeX;
    short maybeY;
    short unk_0x18;
    short xVelocity;
    short yVelocity;
    short unk_0x1e;
    int unk_0x20;
} PermObject;

typedef struct PermObjectList {
    struct PermObject* startingObject;
    struct PermObject* nextObject;
    struct PermObject* currentObj;
} PermObjectList;

typedef struct Actor {
    struct Actor* next;
    struct Actor* linkedActor;
    struct Actor* actorPtr;
    struct PermObject* permObject;
    uint16_t spriteIdx2;
    // 2 byte padding TODO check alignment of struct
    Sprite* spritePtr;
    int typeMaybe;
    uint32_t frameNo;
    RECT someRect;
    RECT rect;
    short xPosMaybe;
    short yPosMaybe;
    short isInAir;
    short HorizontalVelMaybe;
    short verticalVelocityMaybe;
    short inAirCounter;
    uint32_t flags;
} Actor;

typedef struct
{
    short unk_0;
    short unk_2;
    short unk_4;
    short unk_6;
    short xRelated;
    short unk_a;
    uint32_t frameNo;
} ActorVelStruct;

typedef struct
{
    /*HGLOBAL*/ void* soundResource;
    void* soundData;
} Sound;

typedef struct
{
    int leftFrameNo;
    int rightFrameNo;
} PlayerTurnFrameNoLookupTbl;

#define NUM_ACTORS 100
#define NUM_SPRITES 90
#define NUM_STRINGS 20
#define NUM_PERM_OBJECTS 256
#define SMALL_TEXTURE_ATLAS_MAX_SIZE 32

// Actor bit flags

#define FLAG_1 1
#define FLAG_2 2
#define FLAG_4 4
#define FLAG_8 8
#define FLAG_10 0x10
#define FLAG_20 0x20
#define FLAG_40 0x40
#define FLAG_80 0x80

#define BORDER_LEFT 0
#define BORDER_RIGHT 1
#define BORDER_TOP 2
#define BORDER_BOTTOM 3

#define ACTOR_TYPE_0_PLAYER 0
#define ACTOR_TYPE_1_BEGINNER 1
#define ACTOR_TYPE_2_DOG 2
#define ACTOR_TYPE_3_SNOWBOARDER 3
#define ACTOR_TYPE_4_CHAIRLIFT 4
#define ACTOR_TYPE_5_YETI_TOP 5
#define ACTOR_TYPE_6_YETI_BOTTOM 6
#define ACTOR_TYPE_7_YETI_LEFT 7
#define ACTOR_TYPE_8_YETI_RIGHT 8
#define ACTOR_TYPE_9_TREE_ON_FIRE 9
#define ACTOR_TYPE_10_WALKING_TREE 10 // a
#define ACTOR_TYPE_11_MOGULS 11       // b
#define ACTOR_TYPE_12_SLALOM_FLAG 12  // c
#define ACTOR_TYPE_13_TREE 13         // d
#define ACTOR_TYPE_14_ROCK_STUMP 14   // e
#define ACTOR_TYPE_15_BUMP 15         // f
#define ACTOR_TYPE_16_JUMP 16         // 10
#define ACTOR_TYPE_17_SIGN 17         // 11
#define ACTOR_TYPE_18_NOTHING 18      // 12

#endif // SKIFREE_DECOMP_TYPES_H
