#include <stdio.h>

#define HEIGHT_MAX      101 /* ?????????(???1?????????+1) */
#define WIDTH_MAX       101 /* ?????????(???1?????????+1) */

typedef unsigned char   U1;
typedef unsigned short  U2;
typedef unsigned long   U4;
typedef signed   char   S1;
typedef signed   short  S2;
typedef signed   long   S4;

/********************************************************************************/
/* ???   | initData                                                          */
/* ???? | ?????????                                                */
/* ??     | u2InpBlackData ??????????                               */
/*          | u2InpWhiteData ??????????                               */
/* ???   | ??                                                              */
/* ??     | ??                                                              */
/********************************************************************************/
void initData(U2 u2InpBlackData[HEIGHT_MAX][WIDTH_MAX],U2 u2InpWhiteData[HEIGHT_MAX][WIDTH_MAX])
{
    U1  u1CntHeight;
    U1  u1CntWidth;
    
    for(u1CntHeight = 0; u1CntHeight < HEIGHT_MAX; u1CntHeight++ )
    {
        for(u1CntWidth = 0; u1CntWidth < WIDTH_MAX; u1CntWidth++ )
        {
            u2InpBlackData[u1CntHeight][u1CntWidth] = 0;
            u2InpWhiteData[u1CntHeight][u1CntWidth] = 0;
        }
    }
}

/********************************************************************************/
/* ???   | inputData                                                         */
/* ???? | ?????                                                        */
/* ??     | u1Height       ???????                                     */
/*          | u1Width        ???????                                     */
/*          | u2InpBlackData ??????????                               */
/*          | u2InpWhiteData ??????????                               */
/* ???   | ??                                                              */
/* ??     | ??                                                              */
/********************************************************************************/
void inputData(U1 *u1Height,U1 *u1Width,U2 u2InpBlackData[HEIGHT_MAX][WIDTH_MAX],U2 u2InpWhiteData[HEIGHT_MAX][WIDTH_MAX])
{
    int input;
    U1  u1CntHeight;
    U1  u1CntWidth;
    U1  u1TmpDensity;
    scanf("%d",&input);
    *u1Height = (U1)input;
    
    scanf("%d",&input);
    *u1Width = (U1)input;

    for(u1CntHeight = 1; u1CntHeight <= *u1Height; u1CntHeight++ )
    {
        for(u1CntWidth = 1; u1CntWidth <= *u1Width; u1CntWidth++ )
        {
            scanf("%d",&input);
            u1TmpDensity = (U1)input;
            /* ???????????????????????????   */
            /* ?????????????0???                        */
            if((u1CntHeight % 2) == 0)
            {
                if((u1CntWidth % 2) == 0)
                {
                    u2InpBlackData[u1CntHeight][u1CntWidth] = u1TmpDensity;
                    u2InpWhiteData[u1CntHeight][u1CntWidth] = 0;
                }
                else
                {
                    u2InpBlackData[u1CntHeight][u1CntWidth] = 0;
                    u2InpWhiteData[u1CntHeight][u1CntWidth] = u1TmpDensity;
                }
            }
            else
            {
                if((u1CntWidth % 2) == 0)
                {
                    u2InpBlackData[u1CntHeight][u1CntWidth] = 0;
                    u2InpWhiteData[u1CntHeight][u1CntWidth] = u1TmpDensity;
                }
                else
                {
                    u2InpBlackData[u1CntHeight][u1CntWidth] = u1TmpDensity;
                    u2InpWhiteData[u1CntHeight][u1CntWidth] = 0;
                }
            }
        }
    }
}

/********************************************************************************/
/* ???   | calcCumSum                                                        */
/* ???? | ?????                                                        */
/* ??     | u1Height       ???????                                     */
/*          | u1Width        ???????                                     */
/*          | u2InputData    ?????????                                 */
/*          | u2CumData      ???????                                     */
/* ???   | ??                                                              */
/* ??     | ??                                                              */
/********************************************************************************/
void calcCumSum(U1 u1Height,U1 u1Width,U2 u2InputData[HEIGHT_MAX][WIDTH_MAX],U2 u2CumData[HEIGHT_MAX][WIDTH_MAX])
{
    U1  u1CntHeight;
    U1  u1CntWidth;
    
    for(u1CntHeight = 0; u1CntHeight < HEIGHT_MAX; u1CntHeight++ )
    {
        for(u1CntWidth = 0; u1CntWidth < WIDTH_MAX; u1CntWidth++ )
        {
            u2CumData[u1CntHeight][u1CntWidth] = u2InputData[u1CntHeight][u1CntWidth];
        }
    }
    
    /* ???????????????? */
    for(u1CntHeight = 0; u1CntHeight <= u1Height; u1CntHeight++ )
    {
        for(u1CntWidth = 1; u1CntWidth <= u1Width; u1CntWidth++ )
        {
            u2CumData[u1CntHeight][u1CntWidth] += u2CumData[u1CntHeight][u1CntWidth - 1];
        }
    }

    /* ???????????????? */
    for(u1CntHeight = 1; u1CntHeight <= u1Height; u1CntHeight++ )
    {
        for(u1CntWidth = 0; u1CntWidth <= u1Width; u1CntWidth++ )
        {
            u2CumData[u1CntHeight][u1CntWidth] += u2CumData[u1CntHeight - 1][u1CntWidth];
        }
    }
}

/********************************************************************************/
/* ???   | getMaxChcMass                                                     */
/* ???? | ????????????                                          */
/* ??     | u1Height       ???????                                     */
/*          | u1Width        ???????                                     */
/*          | u2CumBlack     ???????????                             */
/*          | u2CumWhite     ???????????                             */
/* ???   | ????                                                          */
/* ??     | ??                                                              */
/********************************************************************************/
U2 getMaxChcMass(U1 u1Height,U1 u1Width,U2 u2CumBlack[HEIGHT_MAX][WIDTH_MAX],U2 u2CumWhite[HEIGHT_MAX][WIDTH_MAX])
{
    U1  u1CntHeight;
    U1  u1CntWidth;
    U1  u1TgtHeight;
    U1  u1TgtWidth;
    U2  u2BlackSum;
    U2  u2WhiteSum;
    U2  u2ChocoMass;
    U2  u2TmpMass;
    
    u2ChocoMass = 0;
    
    /* ???????????? */
    for(u1CntHeight = 1; u1CntHeight <= u1Height; u1CntHeight++ )
    {
        for(u1CntWidth = 1; u1CntWidth <= u1Width; u1CntWidth++ )
        {
            /* ???????????? */
            for(u1TgtHeight = u1CntHeight; u1TgtHeight <= u1Height; u1TgtHeight++ )
            {
                for(u1TgtWidth = u1CntWidth; u1TgtWidth <= u1Width; u1TgtWidth++ )
                {
                    /* 
                        |-|-----------|
                        |A|          B|
                        |-|-----------|
                        | |           |
                        | |           |
                        |C|          D|
                        |-|-----------|
                    A,B,C,D?????????????????
                    
                    D??????????
                    ????D-(B+D)+A??????????????
                    */
                    u2BlackSum = u2CumBlack[u1TgtHeight][u1TgtWidth] 
                                - (u2CumBlack[u1TgtHeight][u1CntWidth - 1] + u2CumBlack[u1CntHeight - 1][u1TgtWidth])
                                + u2CumBlack[u1CntHeight - 1][u1CntWidth - 1];
                    u2WhiteSum = u2CumWhite[u1TgtHeight][u1TgtWidth] 
                                - (u2CumWhite[u1TgtHeight][u1CntWidth - 1] + u2CumWhite[u1CntHeight - 1][u1TgtWidth])
                                + u2CumWhite[u1CntHeight - 1][u1CntWidth - 1];
                    if(u2BlackSum == u2WhiteSum)
                    {
                        u2TmpMass = (u1TgtHeight - u1CntHeight + 1) * (u1TgtWidth - u1CntWidth + 1);
                        if(u2ChocoMass < u2TmpMass)
                        {
                            u2ChocoMass = u2TmpMass;
                        }
                    }
                }
            }
        }
    }
    return u2ChocoMass;
}

/********************************************************************************/
/* ???   | getMaxChcMass                                                     */
/* ???? | ????????                                                  */
/* ??     | u2ChocoMass       ?????                                      */
/* ???   | ????                                                          */
/* ??     | ??                                                              */
/********************************************************************************/
void outputChocoMass(U2 u2ChocoMass)
{
    printf("%d\n",u2ChocoMass);
}

/********************************************************************************/
/* ???   | main                                                              */
/* ???? | main?                                                            */
/* ??     | ??                                                              */
/* ???   | ??                                                              */
/* ??     | ??                                                              */
/********************************************************************************/
int main(void)
{
    U1  u1Height;
    U1  u1Width;
    U2  u2ChocoMass;
    U2  u2ChocoBlack[HEIGHT_MAX][WIDTH_MAX];
    U2  u2ChocoWhite[HEIGHT_MAX][WIDTH_MAX];
    U2  u2CumChcBlack[HEIGHT_MAX][WIDTH_MAX];
    U2  u2CumChcWhite[HEIGHT_MAX][WIDTH_MAX];

    /* ???? */
    initData(u2ChocoBlack,u2ChocoWhite);
    
    /* ??? */
    inputData(&u1Height,&u1Width,u2ChocoBlack,u2ChocoWhite);

    /* ??? */
    calcCumSum(u1Height,u1Width,u2ChocoBlack,u2CumChcBlack);
    calcCumSum(u1Height,u1Width,u2ChocoWhite,u2CumChcWhite);
    
    u2ChocoMass = getMaxChcMass(u1Height,u1Width,u2CumChcBlack,u2CumChcWhite);
    
    /* ??? */    
    outputChocoMass(u2ChocoMass);
} ./Main.c: In function ‘inputData’:
./Main.c:52:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&input);
     ^
./Main.c:55:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&input);
     ^
./Main.c:62:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
             scanf("%d",&input);
             ^