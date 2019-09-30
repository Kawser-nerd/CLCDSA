using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ARC001_A
{
    class Program
    {
        const int MASU_LENGTH = 8;
        static void Main(string[] args)
        {

            List<masu> grid = new List<masu>();
            for (int x = 0; x < MASU_LENGTH; x++)
            {
                for (int y = 0; y < MASU_LENGTH; y++)
                {
                    masu temp = new masu()
                    {
                        x = y,
                        y = x,
                        exists = false,
                        setOK = true
                    };

                    grid.Add(temp);

                }
            }

            for (int x = 0; x < MASU_LENGTH; x++)
            {
                string input = Console.ReadLine();
                int y = 0;
                foreach (var ch in input)
                {
                    int accessIndex = (x * MASU_LENGTH) + y;
                    if (ch == 'Q')
                    {
                        if (!grid[accessIndex].setOK)
                        {
                            Console.WriteLine("No Answer");
                            Console.ReadLine();
                            return;
                        }

                        grid[accessIndex].exists = true;

                        setNG(ref grid, grid[accessIndex]);

                    }
                    y++;
                }
            }

            List<masu> ansGrid = solve(grid);
            if (ansGrid == null)
            {
                Console.WriteLine("No Answer");
                Console.ReadLine();
                return;
            }

            for (int x2 = 0; x2 < MASU_LENGTH; x2++)
            {
                Console.WriteLine("{0}", string.Join("", ansGrid.Skip(x2 * MASU_LENGTH).Take(MASU_LENGTH).Select(c => c.exists ? "Q" : ".")));
            }
            Console.ReadLine();

        }

        static public List<masu> solve(List<masu> grid)
        {
            // ??PickUp
            foreach (masu item in grid.Where(c => c.setOK == true && c.exists == false).ToList())
            {
                int accessIndex = (item.y * MASU_LENGTH) + item.x;
                List<masu> newGrid = new List<masu>(grid.Select(c => c.CloseTo()).ToList());
                newGrid[accessIndex].exists = true;
                setNG(ref newGrid, newGrid[accessIndex]);

                if (newGrid.Where(c => c.exists == true).Count() == 8)
                {
                    return newGrid;
                }
                else
                {
                    newGrid = solve(newGrid);
                    if (newGrid != null)
                        return newGrid;
                }
            }

            return null;
        }

        static public void setNG(ref List<masu> area, masu target)
        {
            // ?
            foreach (var item in area.Select(c => c).Where(c => c.y == target.y))
            {
                item.setOK = false;
            }

            // ?
            foreach (var item in area.Select(c => c).Where(c => c.x == target.x))
            {
                item.setOK = false;
            }

            // ??
            foreach (var item in area.Select(c => c).Where(c => (Math.Abs(c.x - target.x) == Math.Abs(c.y - target.y))))
            {
                item.setOK = false;
            }
        }

    }

    public class masu
    {
        public bool exists = false;
        public bool setOK = false;

        public int x = -1;
        public int y = -1;

        public override string ToString()
        {
            return exists ? "Q" : ".";
        }

        public masu CloseTo()
        {
            return new masu()
            {
                x = this.x,
                y = this.y,
                exists = this.exists,
                setOK = this.setOK
            };
        }
    }
}