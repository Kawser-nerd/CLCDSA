#include<stdio.h>

void mergeSort(int numbers[], int array_size);
void m_sort(int numbers[], int temp[], int left, int right);
void merge(int numbers[], int temp[] ,int left, int mid, int right);

void mergeSort(int numbers[],int array_size)
{
    int temp[array_size];
    for(int i = 0;i < array_size; i++)
    {
        temp[i] = 0;
    }
    m_sort(numbers, temp, 0, array_size - 1);
}

void m_sort(int numbers[], int temp[], int left, int right)
{
    int mid;

    if(right > left)
    {
        mid = (right + left) / 2;
        m_sort(numbers, temp, left, mid);
        m_sort(numbers, temp, mid + 1, right);

        merge(numbers, temp,left, mid+1, right);
    }
}

void merge(int numbers[], int temp[] ,int left, int mid, int right)
{
    int i, left_end, num_elements, tmp_pos;

    left_end = mid - 1;
    tmp_pos = left;
    num_elements = right - left + 1;

    while((left <= left_end) && (mid <= right))
    {
        if(numbers[left] <= numbers[mid])
        {
            temp[tmp_pos] = numbers[left];
            tmp_pos++;
            left++;
        }
        else
        {
            temp[tmp_pos] = numbers[mid];
            tmp_pos++;
            mid++;
        }
    }

    while(left <= left_end)
    {
        temp[tmp_pos] = numbers[left];
        left++;
        tmp_pos++;
    }

    while(mid <= right)
    {
        temp[tmp_pos] = numbers[mid];
        mid++;
        tmp_pos++;
    }

    for(i=0; i <= num_elements; i++)
    {
        numbers[right] = temp[right];
        right--;
    }
}

int main(void){
    int n,m;
    scanf("%d%d",&n,&m);
    
    if(m == 1 || n > m)
    {
        puts("0");
        return 0;
    }
    
    int x[m],y[m-1];
    for(int i = 0; i < m; i++)
    {
        scanf("%d",&x[i]);
    }
    
    mergeSort(x,m);
  
    for(int i = 0; i < m - 1; i++)
    {
        y[i] = x[i+1] - x[i];
    }
    
    
    mergeSort(y,m-1);
    
    int ans = x[m-1] - x[0];
    int count = m-2;
    for(int i = 0; i < n - 1; i++)
    {
        ans -= y[count];
        count--;
    }
    
    printf("%d",ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:78:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&n,&m);
     ^
./Main.c:89:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&x[i]);
         ^