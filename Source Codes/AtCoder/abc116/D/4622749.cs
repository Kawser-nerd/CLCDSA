using System;
using System.Linq;
using System.Collections;
using System.Collections.Generic;

namespace AtCoder
{
    public class Sushi: IComparable<Sushi>
    {
        public int neta;
        public long oishisa;
        public bool isIncluded;

        public Sushi(int t, long d)
        {
            neta = t;
            oishisa = d;
            isIncluded = false;
        }

        public int CompareTo(Sushi param)
        {
            return (oishisa > param.oishisa)? 1 :
                   (oishisa < param.oishisa)? -1 : 0;
        }
    }

    public class SushiTable
    {
        public MyLib.PriorityQueue<Sushi> slist;
        private int[] netalist = new int[100001];
        private int neta = 0;
        private long oishisa = 0;
        private int cnt = 0;
        public int Neta => neta;
        public long Oishisa => oishisa;

        public SushiTable()
        {
            slist = new MyLib.PriorityQueue<Sushi>();
        }

        public void Push(Sushi param)
        {
            if (netalist[param.neta] == 0) neta++;
            netalist[param.neta]++;
            oishisa += param.oishisa;
            param.isIncluded = true;
            slist.Push(param);
        }

        public bool IncreaseNeta(List<Sushi> param)
        {
            bool flag = RemoveMinNeta(param);
            if (flag == false) return false;
            flag = AddMaxNeta(param);
            if (flag) neta++;
            return flag;
        }

        private bool RemoveMinNeta(List<Sushi> param)
        {
            bool flag = false;
            int size = slist.Size;
            for (int i = 0; i < size; i++)
            {
                Sushi s = slist.Pop();
                if (netalist[s.neta] > 1)
                {
                    netalist[s.neta]--;
                    oishisa -= s.oishisa;
                    s.isIncluded = false;
                    flag = true;
                    break;
                }
            }

            return flag;
        }

        private bool AddMaxNeta(List<Sushi> param)
        {
            bool flag = false;
            int size = param.Count;
            for (int i = cnt; i < size; i++)
            {
                if (netalist[param[i].neta] == 0)
                {
                    netalist[param[i].neta]++;
                    oishisa += param[i].oishisa;
                    param[i].isIncluded = true;
                    flag = true;
                    break;
                }
                cnt = i;
            }

            return flag;
        }
    }

    class Program
    {
        public static long CalcScore(int t, long d)
        {
            return d + (long)t * (long)t;
        }

        public static void Main(string[] args)
        {
            long res = 0;
            List<Sushi> remainedSushi = new List<Sushi>();
            SushiTable st = new SushiTable();

            int N;
            long K;
            string[] str = Console.ReadLine().Split(' ');
            N = int.Parse(str[0]);
            K = long.Parse(str[1]);

            for (int i = 0; i < N; i++)
            {
                str = Console.ReadLine().Split(' ');
                int t = int.Parse(str[0]);
                long d = long.Parse(str[1]);
                remainedSushi.Add(new Sushi(t, d));
            }

            remainedSushi = remainedSushi.OrderByDescending(x => x.oishisa).ToList();

            for (int i = 0; i < K; i++)
            {
                st.Push(remainedSushi[i]);
            }

            res = CalcScore(st.Neta, st.Oishisa);
            for (int i = st.Neta; i < N; i++)
            {
                bool flag = st.IncreaseNeta(remainedSushi);
                if (!flag)
                    break;
                long tt = CalcScore(st.Neta, st.Oishisa);
                res = (res < tt) ? tt : res;
            }

            Console.WriteLine(res);
        }
    }
}

namespace MyLib
{
    #region Heap
    public class Heap<T> where T: IComparable<T>
    {
        private List<T> _heap;
        private int _size;
        public int Size => _size;

        public Heap()
        {
            _size = 0;
            _heap = new List<T>();
        }

        public List<T> ToList()
        {
            return _heap;
        }

        public void Push(T elem)
        {
            int _ref = _size;
            _heap.Add(elem);

            while (_ref != 0)
            {
                int i = (_ref - 1) / 2;
                if (_heap[_ref].CompareTo(_heap[i]) < 0) Swap(_ref, i);
                _ref = i;
            }
            _size++;
        }

        public T Pop()
        {
            T ret = _heap[0];
            int _ref = _size - 1;
            _heap[0] = _heap[_ref];
            _heap.RemoveAt(_ref);

            for (int i = 0, j; (j = 2 * i + 1) < _ref;)
            {
                if ((j != _ref - 1) && (_heap[j].CompareTo(_heap[j + 1]) > 0)) j++;
                if (_heap[i].CompareTo(_heap[j]) > 0) Swap(i, j);
                i = j;
            }
            _size--;

            return ret;
        }

        private void Swap(int m, int n)
        {
            T temp = _heap[m];
            _heap[m] = _heap[n];
            _heap[n] = temp;
        }
    }
    #endregion

    #region PriorityQueue
    public class PriorityQueue<T> where T: IComparable<T>
    {
        Heap<T> _priority_queue;
        public int Size => _priority_queue.Size;

        public PriorityQueue()
        {
            _priority_queue = new Heap<T>();
        }

        public List<T> ToList() { return _priority_queue.ToList(); }

        public void Push(T elem) { _priority_queue.Push(elem); }

        public T Pop() { return _priority_queue.Pop(); }
    }
    #endregion
}