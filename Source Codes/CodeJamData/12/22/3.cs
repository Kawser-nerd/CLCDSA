using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GCJDevKit.Tools
{
    // heap of ints as the keys
    //Change priority to smaller
    // add
    // pop
    //initialize with the proper size
    class Heap<V>
    {
        int size = 0;
        private KeyValuePair<int,V> []table;

        public Heap(int maxSize)
        {
            table = new KeyValuePair<int, V>[maxSize];
        }

        private void Heapify(int n)
        {
            if (n == 0) return;
            int parent = (n - 1) / 2;
            if (table[parent].Key > table[n].Key)
            {
                Swap(n, parent);
                Heapify(parent);
            }
        }

        private void BottoMify(int n)
        {
            int leftSon = n*2+1;
            int rightSon = n*2+2;
            if (leftSon >= size) return;
            if (rightSon >= size)
            {
                if (table[leftSon].Key < table[n].Key)
                {
                    Swap(n, leftSon);
                }
            }
            else
            {
                int smallerSon = table[leftSon].Key < table[rightSon].Key ? leftSon : rightSon;
                if (table[smallerSon].Key < table[n].Key)
                {
                    Swap(n, smallerSon);
                    BottoMify(smallerSon);
                }
            }
        }

        private void Swap(int first, int second)
        {
            var z = table[first];
            table[first] = table[second];
            table[second] = z;
            positions[table[first].Value] = first;
            positions[table[second].Value] = second;
        }

        /// <summary>
        /// Adds new element to the heap. You should provide priority along with the value.
        /// </summary>
        /// <param name="priority"></param>
        /// <param name="value"></param>
        public void Add(int priority, V value)
        {
            table[size] = new KeyValuePair<int, V>(priority, value);
            positions[value] = size;
            Heapify(size);
            size++;
        }

        public KeyValuePair<int, V> Pop()
        {
            var v = table[0];
            Swap(0, size - 1);
            size--;
            BottoMify(0);
            positions.Remove(v.Value);
            return v;
        }

        public bool Empty
        {
            get
            {
                return size == 0;
            }
        }

        Dictionary<V, int> positions = new Dictionary<V, int>();

        public bool ContainsValue(V x)
        {
            return positions.ContainsKey(x);
        }

        public void ChangePriorityToSmaller(V value, int newPriority)
        {
            int position = positions[value];
            table[position] = new KeyValuePair<int, V>(newPriority, value);
            Heapify(position);
        }
    }
}
