using namespace std;

#include <iostream>
#include <stdlib.h>
#include <string.h>

using QWORD = unsigned long long;
using SDWORD = int;
using DWORD = unsigned int;
using KNAPSACK_OBJ_ST = struct {
    QWORD dwWeight;
    QWORD dwValue;
};

#define OBJ_NUM_MAX 200
#define MAX_QWORD ((QWORD)(-1))

inline QWORD MAX(QWORD a, QWORD b) 
{ 
    return a > b ? a : b; 
}

inline QWORD MIN(QWORD a, QWORD b)
{
    return a < b ? a : b;
}

class KnapsackDpMap {
  private:
    QWORD *pqwDpMap;
    DWORD dwObjNum;
    DWORD dwDpWidth;
    DWORD dwTableNum;

    inline DWORD getTblIdx(DWORD dwRow, DWORD dwCol) {
        return (dwRow * (this->dwDpWidth + 1) + dwCol);
    };

  public: 
    KnapsackDpMap(DWORD dwObjNum, DWORD dwDpWidth)
    {
        this->dwTableNum = (dwObjNum + 1) * (dwDpWidth + 1);
        QWORD qwAllocSize = (QWORD)sizeof(*(this->pqwDpMap)) * this->dwTableNum;
        if (2LL * 1024LL * 1024LL * 1024LL < qwAllocSize) {
            printf("Memory Allocation Error[%lld]\n", qwAllocSize);
            return;
        }

        this->dwDpWidth = dwDpWidth;
        this->dwObjNum = dwObjNum;
        this->pqwDpMap = (QWORD *)(malloc(qwAllocSize));
        if (NULL == this->pqwDpMap) {
            printf("Memory Allocation Error\n");
            return;
        }
        memset(this->pqwDpMap, 0, qwAllocSize);
    };

    ~KnapsackDpMap(){

    };

    inline void Init(QWORD qwVal)
    {
        for(DWORD dwIdx = 0; dwIdx < dwTableNum; dwIdx++) {
            *(this->pqwDpMap + dwIdx) = qwVal;
        }
    };

    inline void Put(DWORD dwObjIdx, DWORD dwDpColIdx, QWORD qwValue) 
    {
        this->pqwDpMap[getTblIdx(dwObjIdx, dwDpColIdx)] = qwValue;
    };

    inline QWORD Get(DWORD dwObjIdx, DWORD dwDpColIdx)
    {
        QWORD qwRetVal = this->pqwDpMap[getTblIdx(dwObjIdx, dwDpColIdx)];
        return qwRetVal;
    };
};

QWORD solver_Value(
    DWORD dwObjNum,
    DWORD dwMaxWeight,
    DWORD dwValueSum,
    DWORD dwMaxObjWeight, 
    KNAPSACK_OBJ_ST *pstObjs)
{
//    printf("sovler_value\n");
    KnapsackDpMap dpMap(dwObjNum, dwValueSum);

    dpMap.Init(MAX_QWORD - (QWORD)dwMaxObjWeight);
    dpMap.Put(0, 0, 0);

    for (SDWORD lObjIdx = 0; lObjIdx < dwObjNum; lObjIdx++) {
        for (DWORD dwValueIdx = 0; dwValueIdx <= dwValueSum; dwValueIdx++) {
            DWORD dwObjWeight = (pstObjs + lObjIdx)->dwWeight;
            DWORD dwObjValue = (pstObjs + lObjIdx)->dwValue;

            if (dwValueIdx < dwObjValue) {
                dpMap.Put(lObjIdx+1, dwValueIdx, dpMap.Get(lObjIdx, dwValueIdx));
            } else {
                QWORD qwValue1, qwValue2;

                qwValue1 = dpMap.Get(lObjIdx, dwValueIdx);
                qwValue2 = dpMap.Get(lObjIdx, dwValueIdx - dwObjValue) + (QWORD)dwObjWeight;
                dpMap.Put(lObjIdx + 1, dwValueIdx, MIN(qwValue1, qwValue2));
            }
        }
    }

    QWORD qwAnswer = 0;
    for (DWORD dwValueIdx = 0; dwValueIdx <= dwValueSum; dwValueIdx++) {
        if (dpMap.Get(dwObjNum, dwValueIdx) <= dwMaxWeight) {
            qwAnswer = dwValueIdx;
        } 
    }
    return qwAnswer;
}


QWORD solver_Weight(
    DWORD dwObjNum,
    DWORD dwMaxWeight,
    KNAPSACK_OBJ_ST * pstObjs)
{
//    printf("sovler_weight\n");
    KnapsackDpMap dpMap(dwObjNum, dwMaxWeight);

    for (SDWORD lObjIdx = dwObjNum - 1; 0 <= lObjIdx; lObjIdx--) {
        for (DWORD dwDpWeight = 0; dwDpWeight <= dwMaxWeight; dwDpWeight++) {
            DWORD dwObjWeight = (pstObjs + lObjIdx)->dwWeight;
            DWORD dwObjValue = (pstObjs + lObjIdx)->dwValue;

            if (dwDpWeight < dwObjWeight) {
                dpMap.Put(lObjIdx, dwDpWeight, dpMap.Get(lObjIdx + 1, dwDpWeight));
            } else {
                QWORD qwValue1, qwValue2;

                qwValue1 = dpMap.Get(lObjIdx + 1, dwDpWeight);
                qwValue2 = dpMap.Get(lObjIdx + 1, dwDpWeight - dwObjWeight) + (QWORD)dwObjValue;
                dpMap.Put(lObjIdx, dwDpWeight, MAX(qwValue1, qwValue2));
            }
        }
    }

    return dpMap.Get(0, dwMaxWeight);
}

QWORD get_max_value_fn(
    DWORD dwCurObjIdx,
    KNAPSACK_OBJ_ST *pstObjs,
    DWORD dwRestWeight)
{
    if (0 == dwCurObjIdx) {
        if (pstObjs[dwCurObjIdx].dwWeight <= dwRestWeight) {
            return pstObjs[dwCurObjIdx].dwValue;
        } else {
            return 0;
        }
    }
    if (dwRestWeight < pstObjs[dwCurObjIdx].dwWeight) {
        return get_max_value_fn(dwCurObjIdx - 1, pstObjs, dwRestWeight);
    } else {
        QWORD qwValue1, qwValue2;
        qwValue1 = get_max_value_fn(dwCurObjIdx - 1, pstObjs, dwRestWeight - pstObjs[dwCurObjIdx].dwWeight) + pstObjs[dwCurObjIdx].dwValue;
        qwValue2 = get_max_value_fn(dwCurObjIdx - 1, pstObjs, dwRestWeight);
        return MAX(qwValue1, qwValue2);
    }
}

int main() {
    char str[30], *token1, *token2;
    DWORD num_objects;
    DWORD knapsack_weight;
    DWORD dwMaxObjWeight = 0;
    DWORD dwValueSum = 0;
    KNAPSACK_OBJ_ST astObjs[OBJ_NUM_MAX];

    cin.getline(str, sizeof(str));
    num_objects     = atoi(strtok(str, " "));
    knapsack_weight = atoi(strtok(NULL, " "));

    for(int objIdx = 0; objIdx<num_objects; objIdx++) {
        cin.getline(str, sizeof(str));
        astObjs[objIdx].dwValue = atoi(strtok(str, " "));
        astObjs[objIdx].dwWeight = atoi(strtok(NULL, " "));

        dwValueSum += astObjs[objIdx].dwValue;
        dwMaxObjWeight = MAX(astObjs[objIdx].dwWeight, dwMaxObjWeight);
    }

    QWORD answer;
    if ((QWORD)dwMaxObjWeight * (QWORD)num_objects < 63 * 1024 * 1024) {
        answer = solver_Weight(num_objects, knapsack_weight, astObjs);
    } else if ((QWORD)dwValueSum * (QWORD)num_objects < 63 * 1024 * 1024) {
        answer = solver_Value(num_objects, knapsack_weight, dwValueSum, dwMaxObjWeight, astObjs);
    } else {
        answer = get_max_value_fn(num_objects - 1, astObjs, knapsack_weight);
    }

    printf("%llu\n", answer);

    return 0;
} ./Main.cpp:1:17: warning: using directive refers to implicitly-defined namespace 'std'
using namespace std;
                ^
1 warning generated.