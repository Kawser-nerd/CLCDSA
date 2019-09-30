using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Numerics;

namespace Gcj2017Qual {
    class Problem {
        /// <summary> 入力ファイル名 </summary>
        protected readonly string pathInputFile;
        /// <summary> 出力ファイル名 </summary>
        protected readonly string pathOutputFile;

        /// <summary> 入力文字列の保持 </summary>
        protected IEnumerable<string> inputLines;
        /// <summary> 入力文字列の順次取り出し </summary>
        protected IEnumerator<string> ienum;

        /// <summary> 出力回答数 </summary>
        protected int answerCount = 0;


        #region 読み込み行の処理

        /* ToArray(),ToList()は原則、呼び出し側担当で。 */
        /* Parse()も呼び出し側担当でいいのでは？ */

        public IEnumerable<String> getNexts() {
            if (!this.ienum.MoveNext()) {
                return null;
            }
            else {
                return this.ienum.Current.Trim().Split(' ');
            }
        }

        /// <summary>
        /// 
        /// </summary>
        /// public IEnumerable<T> getNexts<T>(Func<String, T> f) where T : struct {
        public IEnumerable<T> getNexts<T>(Func<String, T> f) {
            if (!this.ienum.MoveNext()) {
                return null;
            }
            else {
                return this.ienum.Current.Trim().Split(' ').Select(str => f(str));
            }
        }

        /// <summary>short型の列挙を返します</summary>
        public IEnumerable<Int16> getNextInt16s() {
            return getNexts(Int16.Parse);
        }

        /// <summary>int型の列挙を返します</summary>
        public IEnumerable<Int32> getNextInt32s() {
            return getNexts(Int32.Parse);
        }

        /// <summary>long型の列挙を返します</summary>
        public IEnumerable<Int64> getNextInt64s() {
            return getNexts(Int64.Parse);
        }

        /// <summary>double型の列挙を返します</summary>
        public IEnumerable<Double> getNextDoubles() {
            return getNexts(Double.Parse);
        }

        /// <summary>Decimal型の列挙を返します</summary>
        public IEnumerable<Decimal> getNextDecimals() {
            return getNexts(Decimal.Parse);
        }

        /// <summary>BigInteger型の列挙を返します</summary>
        public IEnumerable<BigInteger> getNextBigIntegers() {
            BigInteger bi;
            return getNexts(str => BigInteger.TryParse(str, out bi) ? bi : -1);
        }

        /// <summary> 入力ファイルより一行読み込む。 </summary>
        /// <returns>文字列</returns>
        public string getNext() {
            if (!this.ienum.MoveNext()) {
                return null;
            }
            else {
                return this.ienum.Current;
            }
        }

        /// <summary> 入力ファイルより複数行読み込む。 </summary>
        /// <returns>文字列の列挙</returns>
        public IEnumerable<string> getNextLines(int cnt) {
            if (cnt <= 0) yield break;
            while (0 < cnt-- && this.ienum.MoveNext()) {
                yield return this.ienum.Current;
            }
        }

        /// <summary> 入力ファイルより複数行読み込む。 </summary>
        /// <returns>文字の列挙の列挙</returns>
        public IEnumerable<List<char>> getNextLinesChars(int cnt) {
            if (cnt <= 0) yield break;
            while (0 < cnt-- && this.ienum.MoveNext()) {
                yield return this.ienum.Current.ToCharArray().ToList();
            }
        }

        /// <summary> 入力ファイルより複数行読み込む。 </summary>
        /// <returns>文字列の列挙</returns>
        public IEnumerable<IEnumerable<string>> getNextLinesToEnumMap(int cnt) {
            if (cnt <= 0) yield break;
            while (0 < cnt-- && this.ienum.MoveNext()) {
                yield return getNexts(str => str);
            }
        }

        private void sample() {
            List<List<string>> x1 = getNextLinesToEnumMap(2).Select(x => x.ToList()).ToList();
            List<IEnumerable<string>> x2 = getNextLinesToEnumMap(2).ToList();
            IEnumerable<List<string>> x3 = getNextLinesToEnumMap(2).Select(x => x.ToList());
            IEnumerable<IEnumerable<string>> x4 = getNextLinesToEnumMap(2);
            var y1 = getNextLinesToEnumMap(2).ToLookup(str => str.Take(2));
        }

        #endregion


        #region 回答処理
        /// <summary>
        /// 行のみで回答（文字列）する。
        /// Case #xx: line
        /// </summary>
        /// <param name="prmStr"></param>
        public void WriteAnswerFullLine(string prmStr) {
            FileInfo fOut = new FileInfo(this.pathOutputFile);
            using (StreamWriter sw = new StreamWriter(fOut.FullName, true)) {
                this.answerCount++;
                sw.WriteLine("Case #{0}: {1}", this.answerCount, prmStr);
                sw.Flush();
            }
        }

        /// <summary>
        /// 行のみで回答（数値：書式指定）する。
        /// Case #xx: 0.00000
        /// </summary>
        /// <param name="prmStr"></param>
        public void WriteAnswerFullLine(Double prmD, string prmFormat) {
            FileInfo fOut = new FileInfo(this.pathOutputFile);
            using (StreamWriter sw = new StreamWriter(fOut.FullName, true)) {
                this.answerCount++;
                sw.WriteLine("Case #{0}: {1:" + prmFormat + "}", this.answerCount, prmD);
                sw.Flush();
            }
        }

        /// <summary>
        /// 複数行で回答する。<br />
        /// Case #xx:<br />
        /// line01<br />
        /// line02<br />
        /// </summary>
        /// <param name="prmStr"></param>
        public void WriteAnswerMultiLine(string[] prmStrs) {
            FileInfo fOut = new FileInfo(this.pathOutputFile);
            using (StreamWriter sw = new StreamWriter(fOut.FullName, true)) {
                this.answerCount++;
                sw.WriteLine("Case #{0}:", this.answerCount);
                foreach (string str in prmStrs) {
                    sw.WriteLine("{0}", str);
                }
                sw.Flush();
            }
        }

        /// <summary>
        /// 配列で回答する。<br />
        /// Case #xx: [line1, line2, line3]<br />
        /// </summary>
        /// <param name="prmStr"></param>
        public void WriteAnswerMultiLineArray(string[] prmStrs) {
            FileInfo fOut = new FileInfo(this.pathOutputFile);
            using (StreamWriter sw = new StreamWriter(fOut.FullName, true)) {
                this.answerCount++;
                sw.WriteLine("Case #{0}: [{1}]", this.answerCount, string.Join(", ", prmStrs));
                sw.Flush();
            }
        }

        /// <summary>
        /// 回答ヘッダのみを書き出す。<br />
        /// Case #xx:<br />
        /// </summary>
        /// <param name="prmStr"></param>
        public void WriteAnswerHeader() {
            FileInfo fOut = new FileInfo(this.pathOutputFile);
            using (StreamWriter sw = new StreamWriter(fOut.FullName, true)) {
                this.answerCount++;
                sw.WriteLine("Case #{0}:", this.answerCount);
                sw.Flush();
            }
        }

        /// <summary>
        /// 行を書き出す。
        /// line
        /// </summary>
        /// <param name="prmStr"></param>
        public void WriteAnswerSubLine(string prmStr) {
            FileInfo fOut = new FileInfo(this.pathOutputFile);
            using (StreamWriter sw = new StreamWriter(fOut.FullName, true)) {
                sw.WriteLine("{0}", prmStr);
                sw.Flush();
            }
        }

        #endregion

        #region コンストラクタ、初期化処理
        private Problem() {
            inputLines = new List<string>();
        }

        private Problem(string pathIn, string pathOut)
            : this() {
            this.pathInputFile = pathIn;
            this.pathOutputFile = pathOut;
        }

        /// <summary>
        /// 初期化処理
        /// </summary>
        /// <param name="args"></param>
        /// <returns></returns>
        public static Problem createProblem(string[] args) {
            Problem ret;
            if (args.Length < 1) {
                Console.WriteLine("Error: arguments");
                return null;
            }
            ret = new Problem(args[0], args[0] + ".out");
            FileInfo fIn = new FileInfo(ret.pathInputFile);
            Console.WriteLine("reading..." + fIn.FullName);
            if (!fIn.Exists) {
                Console.WriteLine("Error: input file");
                return null;
            }
            // 入力ファイルを全部読み込む。
            List<string> input = new List<string>();
            using (StreamReader sr = new StreamReader(fIn.FullName)) {
                string line;
                while ((line = sr.ReadLine()) != null) {
                    input.Add(line);
                }
            }
            ret.inputLines = input;
            ret.ienum = ret.inputLines.GetEnumerator();
            return ret;
        }
        #endregion
    }
}
