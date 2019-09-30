using System;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
using System.IO;
using System.Text.RegularExpressions;
using System.Text;
using System.Diagnostics;
using System.Globalization;
using static System.Linq.Enumerable;

namespace B
{
	class Program
	{
		static void Run(string[] args)
		{
			var x = Int;
			var y = Int;
			var z = Int;
			PrintLine((x - z) / (y + z));
		}



		static void Main(string[] args)
		{
			Run(args);
#if DEBUG
			Console.Write("Press any key...");
			Console.ReadKey();
#endif
		}

		/// <summary>
		/// Output any value.
		/// </summary>
		/// <typeparam name="T">type of value.</typeparam>
		/// <param name="value">value</param>
		[DebuggerNonUserCode]
		static void Print<T>(T value)
		{
			Console.Write(value);
		}
		/// <summary>
		/// Output any value on a line.
		/// </summary>
		/// <typeparam name="T">type of value</typeparam>
		/// <param name="value">value</param>
		[DebuggerNonUserCode]
		static void PrintLine<T>(T value)
		{
			Console.WriteLine(value);
		}

		/// <summary>
		/// Input a word
		/// </summary>
		static string Word
		{
			[DebuggerNonUserCode]
			get
			{
				char c;
				while (char.IsWhiteSpace(c = (char)Console.Read()))
				{
					continue;
				}

				var builder = new StringBuilder();
				do
				{
					builder.Append(c);
				}
				while (!char.IsWhiteSpace(c = (char)Console.Read()));

				return builder.ToString();
			}
		}
		/// <summary>
		/// Input a line
		/// </summary>
		static string Line
		{
			[DebuggerNonUserCode]
			get
			{
				return Console.ReadLine();
			}
		}
		/// <summary>
		/// Input bool
		/// </summary>
		static bool Bool
		{
			[DebuggerNonUserCode]
			get
			{
				return bool.Parse(Word);
			}
		}
		/// <summary>
		/// Input char
		/// </summary>
		static char Char
		{
			[DebuggerNonUserCode]
			get
			{
				return char.Parse(Word);
			}
		}
		/// <summary>
		/// Input byte
		/// </summary>
		static byte Byte
		{
			[DebuggerNonUserCode]
			get
			{
				return byte.Parse(Word);
			}
		}
		/// <summary>
		/// Input ushort
		/// </summary>
		static ushort UShort
		{
			[DebuggerNonUserCode]
			get
			{
				return ushort.Parse(Word);
			}
		}
		/// <summary>
		/// Input uint
		/// </summary>
		static uint UInt
		{
			[DebuggerNonUserCode]
			get
			{
				return uint.Parse(Word);
			}
		}
		/// <summary>
		/// Input ulong
		/// </summary>
		static ulong ULong
		{
			[DebuggerNonUserCode]
			get
			{
				return ulong.Parse(Word);
			}
		}
		/// <summary>
		/// Input sbyte
		/// </summary>
		static sbyte SByte
		{
			[DebuggerNonUserCode]
			get
			{
				return sbyte.Parse(Word);
			}
		}
		/// <summary>
		/// Input short
		/// </summary>
		static short Short
		{
			[DebuggerNonUserCode]
			get
			{
				return short.Parse(Word);
			}
		}
		/// <summary>
		/// Input int
		/// </summary>
		static int Int
		{
			[DebuggerNonUserCode]
			get
			{
				return int.Parse(Word);
			}
		}
		/// <summary>
		/// Input long
		/// </summary>
		static long Long
		{
			[DebuggerNonUserCode]
			get
			{
				return long.Parse(Word);
			}
		}
		/// <summary>
		/// Input decimal
		/// </summary>
		static decimal Decimal
		{
			[DebuggerNonUserCode]
			get
			{
				return decimal.Parse(Word);
			}
		}
		/// <summary>
		/// Input variable length integer
		/// </summary>
		static BigInteger Integer
		{
			[DebuggerNonUserCode]
			get
			{
				return BigInteger.Parse(Word);
			}
		}
		/// <summary>
		/// Input float
		/// </summary>
		static float Float
		{
			[DebuggerNonUserCode]
			get
			{
				return float.Parse(Word);
			}
		}
		/// <summary>
		/// Input double
		/// </summary>
		static double Double
		{
			[DebuggerNonUserCode]
			get
			{
				return double.Parse(Word);
			}
		}

		/// <summary>
		/// Input hex int
		/// </summary>
		static int Hex
		{
			[DebuggerNonUserCode]
			get
			{
				return int.Parse(Word, NumberStyles.HexNumber);
			}
		}
		/// <summary>
		/// Input hex int
		/// </summary>
		static int HexInt
		{
			[DebuggerNonUserCode]
			get
			{
				return Hex;
			}
		}
		/// <summary>
		/// Input hex long
		/// </summary>
		static long HexLong
		{
			[DebuggerNonUserCode]
			get
			{
				return long.Parse(Word, NumberStyles.HexNumber);
			}
		}
		/// <summary>
		/// Input variable length hex integer
		/// </summary>
		static BigInteger HexInteger
		{
			[DebuggerNonUserCode]
			get
			{
				return BigInteger.Parse(Word, NumberStyles.HexNumber);
			}
		}
	}
}