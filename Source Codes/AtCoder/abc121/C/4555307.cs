using System;

class _3
{
    static void Main(string[] args)
    {
        string[] input = Console.ReadLine().Split(' ');
        int N = int.Parse(input[0]);
        int M = int.Parse(input[1]);

        var store = new Store[N];

        for(int i = 0; i < N; i++)
        {
            input = Console.ReadLine().Split(' ');
            store[i] = new Store();
            store[i].A = int.Parse(input[0]);
            store[i].B = int.Parse(input[1]);
        }

        Array.Sort(store);

        long money = 0;
        long count = 0;
        for(int i = 0; i < N;i++)
        {

            long n = 0;
            if(M < count + store[i].B)
            {
                n = M - count;
            } else
            {
                n = store[i].B;
            }
            money += n * store[i].A;
            count += n;
            
            if(count == M)
            {
                break;
            }
        }

        Console.WriteLine(money);
    }

    class Store : IComparable<Store>
    {
        public int A { get; set; }
        public int B { get; set; }

        public int CompareTo(Store other)
        {
            return A - other.A;
        }
    }
}