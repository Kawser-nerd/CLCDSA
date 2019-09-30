using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace codejam {
    class Directory {
        public Dictionary<string, Directory> SubDirs = new Dictionary<string, Directory>();
    }

    class Program {
        static int CreateDirs(string[] directories, Directory root) {
            Directory current = root;
            int nNew = 0;

            foreach (string dirName in directories) {
                if (!current.SubDirs.ContainsKey(dirName)) {
                    current.SubDirs.Add(dirName, new Directory());
                    nNew++;
                }

                current = current.SubDirs[dirName];
            }

            return nNew;
        }

        static void Main(string[] args) {
            FileStream ofs = new FileStream("A-small.out", FileMode.Create);
            StreamWriter sw = new StreamWriter(ofs);

            using (FileStream fs = new FileStream("A-small.in", FileMode.Open)) {
                using (StreamReader sr = new StreamReader(fs)) {
                    int nTests = Int32.Parse(sr.ReadLine());

                    for (int testNo = 0; testNo < nTests; testNo++) {
                        string[] nm = sr.ReadLine().Split(new[] {' '}, StringSplitOptions.RemoveEmptyEntries);
                        int nExisting = Int32.Parse(nm[0]);
                        int nNew = Int32.Parse(nm[1]);

                        Directory root = new Directory();

                        for (int dirNo = 0; dirNo < nExisting; dirNo++) {
                            CreateDirs(sr.ReadLine().Split(new[] { '/' }, StringSplitOptions.RemoveEmptyEntries), root);
                        }

                        int nNewDirs = 0;

                        for (int dirNo = 0; dirNo < nNew; dirNo++) {
                            nNewDirs += CreateDirs(sr.ReadLine().Split(new[] { '/' }, StringSplitOptions.RemoveEmptyEntries), root);
                        }

                        sw.WriteLine(String.Format("Case #{0}: {1}", testNo + 1, nNewDirs));
                    }
                }
            }
            sw.Dispose();
            ofs.Dispose();
        }
    }
}
