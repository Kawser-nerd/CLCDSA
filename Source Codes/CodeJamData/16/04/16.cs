using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace QualificationRound
{
    public class Fractiles : Problem
    {
        private Dictionary<int, List<long>> powers;

        protected override void Initialise(string inputFilePath)
        {
            base.Initialise(inputFilePath);
            this.powers = new Dictionary<int, List<long>>();
        }

        protected override string SolveCase()
        {
            var parameters = this.ReadNextLineAsInt32Array();
            var k = parameters[0];
            var c = parameters[1];
            var s = parameters[2];

            var r = this.RequiredNumberOfStudents(k, c);

            if (r > s)
            {
                return "IMPOSSIBLE";
            }

            var tilesToCheck = Enumerable.Range(0, r)
                .Select(i => this.TileToCheck(k, c, i * c + 1, Math.Min(k, (i + 1) * c)));

            return string.Join(" ", tilesToCheck);
        }

        private int RequiredNumberOfStudents(int k, int c)
        {
            return (k / c) + ((k % c) > 0 ? 1 : 0);
        }

        private long TileToCheck(int k, int c, int firstTile, int lastTile)
        {
            long tile = 1;
            
            for (int i = firstTile; i <= lastTile; i++)
            {
                tile += (i - 1) * this.CalculatePower(k, c - (i - firstTile + 1));
            }

            return tile;
        }

        private long CalculatePower(int n, int e)
        {
            if (!this.powers.ContainsKey(n))
            {
                this.powers.Add(n, new List<long> { 1 });
            }

            while (this.powers[n].Count < e + 1)
            {
                this.powers[n].Add(this.powers[n].Last() * n);
            }

            return this.powers[n][(int)e];
        }
    }
}
