#define LARGE_INPUT

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BathroomStalls
{
#if !LARGE_INPUT
    class SpaceInfo
    {
        public int size;
        public int count;
    }
#else
    class SpaceInfo
    {
        public long size;
        public long count;
    }
#endif // !LARGE_INPUT

    class BathroomStalls
    {
        static void Main(string[] args)
        {
            int numberOfSamples = int.Parse(Console.ReadLine());

            for (int sp = 0; sp < numberOfSamples; sp++)
            {
                // Read each sample         
                string[] values = Console.ReadLine().Split(' ');
                long numberOfStalls = long.Parse(values[0]);
                long numberOfPeople = long.Parse(values[1]);
                SolveTheProblem(sp + 1, numberOfStalls, numberOfPeople);
            }
        }

        static List<SpaceInfo> spaces = new List<SpaceInfo>();

#if !LARGE_INPUT
        static void AddSpace(int spaceSize)
        {
            for (int i = 0; i < spaces.Count; i++)
            {
                if (spaces[i].size == spaceSize)
                {
                    spaces[i].count++;
                    return;
                }
            }

            spaces.Add(new SpaceInfo() { size = spaceSize, count = 1 });
        }

        static void SplitSpace(SpaceInfo space, out int leftHalf, out int rightHalf)
        {
            space.count--;
            if (space.count <= 0)
                spaces.RemoveAt(0);

            leftHalf = (space.size - 1) / 2;
            rightHalf = (space.size - 1) - leftHalf;

            AddSpace(rightHalf);

            if (leftHalf > 0)
            {
                AddSpace(leftHalf);
            }
        }
#else
        static void AddMultiSpaces(long spaceSize, long quantity)
        {
            for (int i = 0; i < spaces.Count; i++)
            {
                if (spaces[i].size == spaceSize)
                {
                    spaces[i].count += quantity;
                    return;
                }
            }

            spaces.Add(new SpaceInfo() { size = spaceSize, count = quantity });
        }

        static void SplitMultiSpaces(ref long peopleCount, out long leftHalf, out long rightHalf)
        {
            SpaceInfo largestSpaces = spaces[0];
            peopleCount -= largestSpaces.count;

            leftHalf = (largestSpaces.size - 1) / 2;
            rightHalf = (largestSpaces.size - 1) - leftHalf;

            if (peopleCount <= 0) return;

            spaces.RemoveAt(0);

            AddMultiSpaces(rightHalf, largestSpaces.count);

            if (leftHalf > 0)
            {
                AddMultiSpaces(leftHalf, largestSpaces.count);
            }
        }

#endif // LARGE_INPUT
        static void CheckLastStall(long stallCount, long peopleCount, out long maxSpace, out long minSpace)
        {
            maxSpace = 0;
            minSpace = 0;

            spaces.Clear();
            spaces.Add(new SpaceInfo() { size = stallCount, count = 1 });

#if !LARGE_INPUT
            for (int i = 0; i < peopleCount; i++)
            {
                SplitSpace(spaces[0], out minSpace, out maxSpace);
            }
#else
            while (peopleCount > 0)
            {
                SplitMultiSpaces(ref peopleCount, out minSpace, out maxSpace);
            }
#endif // LARGE_INPUT
        }

        static void SolveTheProblem(int sp, long numberOfStalls, long numberOfPeople)
        {
            // Calculation
            long minSpace;
            long maxSpace;
            CheckLastStall(numberOfStalls, numberOfPeople, out maxSpace, out minSpace);

            // Print results
            Console.Write("Case #{0}: {1} {2}", sp, maxSpace, minSpace);
            Console.WriteLine();
        }
    }
}
