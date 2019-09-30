using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Diagnostics;
using System.Text.RegularExpressions;

namespace MainApp
{
    public enum DivModOperationType
    {
        DivideOnly = 0,
        ModulusOnly,
        DivAndMod
    }

    /// <summary>
    /// Summary description for BigNum.
    /// </summary>
    public struct BigInt
    {
        #region Private Data
        private const int D_AND_C_THRESHOLD = 33;
        private const int ARRAY_ALLOC_SIZE = 500;

        private ushort[] _bitblock;
        private int _numChunks, _numDigits;
        private short _sign;
        private int _bitblockArraySize;
        private int _initialCapacity;
        #endregion

        #region Constructors

        public BigInt(int initialValue)
            : this(0, initialValue)
        {
        }

        private BigInt(int capacity, int initialValue)
            : this(capacity, false)
        {
            InitBigIntFromString(initialValue.ToString());
        }

        public BigInt(Int64 initialValue)
            : this(0, initialValue)
        {
        }

        private BigInt(int capacity, Int64 initialValue)
            : this(capacity, false)
        {
            InitBigIntFromString(initialValue.ToString());
        }

        public BigInt(string initialValue)
            : this(0, initialValue)
        {
        }

        private BigInt(int capacity, string initialValue)
            : this(capacity, false)
        {
            InitBigIntFromString(initialValue);
        }

        private BigInt(int initialCapacity, bool notUsed)
            : this()
        {
            _initialCapacity = initialCapacity;
            if (initialCapacity > 0)
            {
                //Caller has specified a capacity (only privileged methods do this).
                _bitblockArraySize = initialCapacity;
                _bitblock = new ushort[_bitblockArraySize];
            }
        }
        #endregion

        #region Public Properties

        /// <summary>
        /// Gets the size of the internal data structure used to store the BigInt.
        /// </summary>
        public int Capacity
        {
            get { return (_bitblock == null ? 0 : _bitblock.Length); }
        }

        public short Sign { get { return _sign; } }
        public int NumDigits { get { return _numDigits; } }
        public int NumChunks { get { return _numChunks; } }

        public bool IsEven
        {
            get
            {
                if (IsZero())
                    return true;
                return (GetChunk(0) & 1) == 0;
            }
        }

        #endregion

        #region Public Methods
        /// <summary>
        /// Compares two BigInts		
        /// </summary>
        /// <returns>1 if a > b, 0 if a == b, -1 if a is less than b</returns>
        public static short Compare(BigInt a, BigInt b)
        {
            a.EnsureInitialized();
            b.EnsureInitialized();

            if (a.IsZero() && b.IsZero())
                return 0;

            if (a.Sign != b.Sign)
            {	//a and b have different signs
                if (a.Sign == 1)
                    return 1;  //every positive number is bigger than every negative number
                else
                    return -1; //and vice versa
            }
            else if (a.NumDigits > b.NumDigits)
            {	//a has more digits than b (a and b have same sign)
                return a.Sign; // If both are positive then a > b.  If both are negative then a < b
            }
            else if (a.NumDigits < b.NumDigits)
            {	//a has fewer digits than b (a and b have same sign)
                return (short)-a.Sign; // If both are positive then a < b.  If both are negative then a > b
            }
            else
            {
                short aChunk, bChunk;
                for (int i = a.NumChunks - 1; i >= 0; i--)
                {
                    aChunk = a.GetChunk(i);
                    bChunk = b.GetChunk(i);
                    if (aChunk < bChunk)
                        return -1;
                    else if (aChunk > bChunk)
                        return 1;
                }
                //they must be equal
                return 0;
            }
        }

        public BigInt Abs()
        {
            EnsureInitialized();

            BigInt result = this;
            if (result._sign == -1)
                result._sign = 1;

            return result;
        }

        public BigInt ShortMultiply(ushort c)
        {
            // optimized special case for multiplying a BigInt by a ushort
            // (normal operator* will work OK but this is a bit faster)

            //Work out roughly how many digits the result will contain and create a BigInt with sufficient capacity.
            int numCDigits = Math.Abs(c).ToString().Length;
            BigInt result = new BigInt(StorageSizeForDigits(NumDigits + numCDigits), 0);

            BigInt currChunkResult = 0;
            int carry = 0, currChunkProduct;

            for (int chunkIndex = 0; chunkIndex < NumChunks; chunkIndex++)
            {
                currChunkProduct = c * GetChunkAbsolute(chunkIndex) + carry;
                carry = currChunkProduct / 1000;
                result.AppendChunk((ushort)(currChunkProduct - (carry * 1000)));
            }
            if (carry > 0)
                result.AppendChunk((ushort)carry);
            result._sign = this.Sign;
            result.AfterUpdate();
            return result;
        }

        public static void DivAndMod(BigInt a, BigInt b, out BigInt remainder, out BigInt result)
        {
            a.EnsureInitialized();
            b.EnsureInitialized();
            DivAndMod(DivModOperationType.DivAndMod, a, b, out remainder, out result);
        }

        /// <summary>
        /// Returns a number raised to a positive integer power.
        /// </summary>
        /// <param name="baseNum">The BigInt to be raised to a power.</param>
        /// <param name="exponent">The (non-negative) integer exponent.</param>
        /// <returns>A BigInt containing the value of baseNum to the power of exponent.</returns>
        public static BigInt Power(BigInt baseNum, uint exponent)
        {
            if (exponent == 0)
            {
                return 1;
            }
            else if (exponent == 1)
            {
                return baseNum;
            }

            //Build up an array of [baseNum^1, baseNum^2, baseNum^4, baseNum^8 ....]
            //Then use the "bits" that make up the binary version of the exponent to tell us which
            // of these results to multiply to get baseNum ^ exponent.
            BigInt result = ((exponent & 1) == 0) ? 1 : baseNum;
            int maxRequired = (int)Math.Ceiling(Math.Log(exponent, 2));
            BigInt[] arrBuildingBlockPowers = new BigInt[maxRequired + 1];
            arrBuildingBlockPowers[0] = baseNum;
            for (int currBit = 1, currPower2 = 2; currPower2 <= exponent; currBit++, currPower2 = currPower2 << 1)
            {
                arrBuildingBlockPowers[currBit] = arrBuildingBlockPowers[currBit - 1] * arrBuildingBlockPowers[currBit - 1];
                if ((exponent & currPower2) > 0)
                {
                    result *= arrBuildingBlockPowers[currBit];
                }
            }
            return result;
        }

        public static BigInt ModPower(BigInt a, BigInt b, BigInt c)
        {	// returns (a ^ b) mod c
            // eg 28 ^ 23 mod 55 = 7

            // There's a trick to this.  a ^ b is usually way too big to handle, so we break it 
            // into pieces, using the fact that xy mod c = ( x mod c )( y mod c ) mod c.
            // Please see www.carljohansen.co.uk/rsa for a full explanation.

            a.EnsureInitialized();
            b.EnsureInitialized();
            c.EnsureInitialized();

            int numBdigits = b.NumDigits;
            BigInt prevResult, finalProduct = 1;
            int i;
            BigInt[] arrResidues = new BigInt[numBdigits + 1];
            BigInt accumulation2, accumulation4, accumulation8;
            arrResidues[0] = a;
            prevResult = arrResidues[0];

            for (i = 1; i < numBdigits; i++)
            {
                //have to calculate (prevResult^10) mod c.  This is (prevResult^2^2^2) mod c * (prevResult^2) mod c
                accumulation2 = (prevResult * prevResult) % c;
                accumulation4 = (accumulation2 * accumulation2) % c;
                accumulation8 = (accumulation4 * accumulation4) % c;

                arrResidues[i] = (accumulation2 * accumulation8) % c;
                prevResult = arrResidues[i];
            }

            for (i = numBdigits - 1; i >= 0; i--)
            {
                int currChunk = b.GetChunkAbsolute(i / 3);
                int currDigit;
                if (i % 3 == 0)
                    currDigit = currChunk % 10;
                else if (i % 3 == 1)
                    currDigit = (currChunk % 100) / 10;
                else
                    currDigit = currChunk / 100;
                for (int j = 0; j < currDigit; j++)
                {
                    finalProduct *= arrResidues[i];
                    finalProduct %= c;
                }
            }

            return finalProduct;
        }
        #endregion

        #region Public Operators
        public static implicit operator BigInt(int a)
        {	//allows you to write this: BigInt myBigInt = 123456789;
            return new BigInt(a);
        }

        public static implicit operator BigInt(long a)
        {	//allows you to write this: BigInt myBigInt = 123456789;
            return new BigInt(a);
        }

        public static implicit operator BigInt(string a)
        {	//allows you to write this: BigInt myBigInt = "123456789012345678901234567890";
            return new BigInt(a);
        }

        public static BigInt operator +(BigInt a, BigInt b)
        {
            a.EnsureInitialized();
            b.EnsureInitialized();

            bool isSubtraction = false;
            BigInt result = new BigInt(Math.Max(a.Capacity, b.Capacity), 0);

            if (a.Sign != b.Sign)
            {
                bool doSignSwapAddition = false;
                if (a.Sign == -1)
                    doSignSwapAddition = (BigInt.CompareMagnitudes(a, b) == 1);
                else //b.Sign == -1					
                    doSignSwapAddition = (BigInt.CompareMagnitudes(a, b) == -1);
                if (doSignSwapAddition)
                {	// our standard addition algorithm doesn't work when a < 0 and b > 0 and |a| > |b| (or vice versa)
                    // becauase we don't look ahead to see if we can borrow, so instead calculate -((-a) + (-b))
                    a._sign = (short)-a.Sign;
                    b._sign = (short)-b.Sign;
                    result = -(a + b);
                    a._sign = (short)-a.Sign;	// put signs back
                    b._sign = (short)-b.Sign;	// the way they were
                    return result;
                }
                else
                    isSubtraction = true;
            }

            int currChunkSum = 0, carry = 0, currChunkToAppend;
            int numChunksToAdd = MaxNumChunks(a, b);

            for (int i = 0; i < numChunksToAdd; i++)
            {
                short borrow = 0, aChunk = a.GetChunk(i), bChunk = b.GetChunk(i);
                if (isSubtraction && ((a.Sign == 1 && (aChunk + carry < Math.Abs(bChunk)))
                                    || (b.Sign == 1 && (bChunk + carry < Math.Abs(aChunk)))))
                    //we're adding +ve and -ve, and the chunk in the positive number (combined with carry)
                    // is smaller than the chunk in the negative number, so have to borrow
                    borrow = 1000;
                currChunkSum = aChunk + bChunk + borrow + carry;
                if (borrow > 0)
                {
                    carry = -1;
                    currChunkToAppend = currChunkSum;
                }
                else if (currChunkSum >= 1000)
                {
                    carry = 1;
                    currChunkToAppend = currChunkSum - 1000;
                }
                else if (currChunkSum <= -1000)
                {
                    carry = -1;
                    currChunkToAppend = (-currChunkSum) - 1000;
                }
                else
                {
                    carry = 0;
                    currChunkToAppend = Math.Abs(currChunkSum);
                }
                result.AppendChunk((ushort)currChunkToAppend);
            }
            if (carry != 0)
                result.AppendChunk((ushort)Math.Abs(carry));

            if (a._sign == b._sign)
                result._sign = a._sign;
            else
                result._sign = (currChunkSum < 0) ? (short)-1 : (short)1;

            result.AfterUpdate();
            return result;
        }

        public static BigInt operator /(BigInt a, BigInt b)
        {
            a.EnsureInitialized();
            b.EnsureInitialized();
            BigInt result, dummy;
            DivAndMod(DivModOperationType.DivideOnly, a, b, out dummy, out result);
            return result;
        }

        public static BigInt operator %(BigInt a, BigInt b)
        {
            a.EnsureInitialized();
            b.EnsureInitialized();
            BigInt remainder, dummy;
            DivAndMod(DivModOperationType.ModulusOnly, a, b, out remainder, out dummy);
            return remainder;
        }

        public static BigInt operator ^(BigInt a, uint b)
        {
            a.EnsureInitialized();
            return BigInt.Power(a, b);
        }

        public static BigInt operator -(BigInt a, BigInt b)
        {
            a.EnsureInitialized();
            b.EnsureInitialized();
            b._sign = (short)-b.Sign;	// flip the sign of b
            BigInt result = a + b;		// calculate (a) + (-b)
            b._sign = (short)-b.Sign;	// put the sign back the way it was
            return result;
        }

        public static BigInt operator -(BigInt a)
        {	//unary minus	
            a.EnsureInitialized();
            BigInt negA = a;
            if (!a.IsZero())
                negA._sign = (short)-a._sign;
            return negA;
        }

        public static BigInt operator *(BigInt a, BigInt b)
        {
            a.EnsureInitialized();
            b.EnsureInitialized();

            if (MinNumChunks(a, b) >= D_AND_C_THRESHOLD)
                // for larger numbers use faster divide-and-conquer routine
                return BigInt.DivideAndConquerMultiply(a, b);

            //perform multiplication using standard O(N^2) algorithm			
            BigInt result = new BigInt(StorageSizeForDigits(a.NumDigits + b.NumDigits), 0);
            BigInt currChunkResult = new BigInt(result.Capacity + 8, 0);
            short resultSign = (short)(a.Sign * b.Sign);  //the sign that the result will have
            int carry, aChunks = a.NumChunks, bChunks = b.NumChunks;

            for (int aChunkIndex = 0; aChunkIndex < aChunks; aChunkIndex++)
            {
                carry = 0;
                short aChunk = a.GetChunkAbsolute(aChunkIndex);
                if (aChunk > 0)
                {
                    int currChunkProduct = 0;
                    for (int bChunkIndex = 0; bChunkIndex < bChunks; bChunkIndex++)
                    {
                        currChunkProduct = aChunk * b.GetChunkAbsolute(bChunkIndex) + carry;
                        carry = currChunkProduct / 1000;
                        currChunkResult.AppendChunk((ushort)(currChunkProduct - (carry * 1000)));
                    }
                    if (carry > 0)
                        currChunkResult.AppendChunk((ushort)carry);
                    result += currChunkResult;
                }
                // set currChunkResult back to just its RHS zero padding...
                currChunkResult._numChunks = aChunkIndex;
                // ...and add another chunk of zero padding for the next round
                currChunkResult.AppendChunk(0);
            }
            result._sign = resultSign;
            result.AfterUpdate();
            return result;
        }

        public static BigInt operator ++(BigInt a)
        {
            a.EnsureInitialized();
            return a + 1;
        }

        public static BigInt operator --(BigInt a)
        {
            a.EnsureInitialized();
            return a - 1;
        }

        public static BigInt operator <<(BigInt a, int n)
        {
            if (n < 0)
            {
                throw new ArgumentOutOfRangeException("n", "Shift amount must not be negative.");
            }

            //return a BigInt which is a padded on the right with n zeros
            a.EnsureInitialized();
            //Create a BigInt that should have enough capacity for the result (to save having to do slow array resizes).
            BigInt result = new BigInt(StorageSizeForDigits(a.NumChunks + n), 0);
            int i, shiftRemaining, mask, shifter, currChunk, carry = 0;

            for (shiftRemaining = n; shiftRemaining > 2; shiftRemaining -= 3)  // add chunks of 3 zeros until 2 digits or less remaining
                result.AppendChunk(0);

            switch (shiftRemaining)
            {
                case 0:	// n is a multiple of three, so all that's left is to copy the digits of a
                    for (i = 0; i < a.NumChunks; i++)
                        result.AppendChunk((ushort)(a.GetChunkAbsolute(i)));
                    break;
                case 1: // n not multiple of 3 so need some intra-chunk shifting
                case 2:
                    if (shiftRemaining == 1)
                    { mask = 100; shifter = 10; }
                    else
                    { mask = 10; shifter = 100; }
                    for (i = 0; i < a.NumChunks; i++)
                    {
                        currChunk = a.GetChunkAbsolute(i);
                        result.AppendChunk((ushort)((currChunk % mask) * shifter + carry));
                        carry = currChunk / mask;
                    }
                    break;
            }
            result._sign = a.Sign;
            result.AfterUpdate();
            return result;
        }

        public static bool operator <(BigInt a, BigInt b)
        { return (Compare(a, b) < 0); }

        public static bool operator <=(BigInt a, BigInt b)
        { return (Compare(a, b) <= 0); }

        public static bool operator >(BigInt a, BigInt b)
        { return (Compare(a, b) > 0); }

        public static bool operator >=(BigInt a, BigInt b)
        { return (Compare(a, b) >= 0); }

        public static bool operator ==(BigInt a, BigInt b)
        { return (Compare(a, b) == 0); }

        public static bool operator !=(BigInt a, BigInt b)
        { return (Compare(a, b) != 0); }

        public override bool Equals(object obj)
        { return (this == (BigInt)obj); }

        public override int GetHashCode()
        { return this.ToString().GetHashCode(); }

        public override string ToString()
        {
            EnsureInitialized();
            if (IsZero())
                return ("0");

            string result = String.Empty;

            for (int i = 0; i < NumChunks; i++)
                if (i < NumChunks - 1)
                    result = System.String.Format("{0:000}", GetChunkAbsolute(i)) + result;
                else
                    result = GetChunkAbsolute(i).ToString() + result;

            if (_sign == -1)
                result = "-" + result;
            return result;
        }
        #endregion

        #region Private Methods
        // This array says, for example, that
        private static ushort[,] mask = {	{ 0, 0,  0x03FF, 0x0000, 0xFC00, 0xFFFF },	// within a block of 8 chunks, (stored in 5 shorts)
											{ 0, 10, 0xFC00, 0x000F, 0x03FF, 0xFFF0 },  // the fourth chunk spans short #1 and short #2
											{ 1, 4,  0x3FF0, 0x0000, 0xC00F, 0xFFFF },  // To obtain it, combine short #2 and short #1 to
											{ 1, 14, 0xC000, 0x00FF, 0x3FFF, 0xFF00 },  // make an int, and mask the int with 0x00FFC000.
											{ 2, 8,  0xFF00, 0x0003, 0x00FF, 0xFFFC },  // Shift the result right 14 bits to get the
											{ 3, 2,  0x0FFC, 0x0000, 0xF003, 0xFFFF },  // the fourth chunk.  Before setting it, AND short #1 with 
											{ 3, 12, 0xF000, 0x003F, 0x0FFF, 0xFFC0 },  // 0x3FFF (= ~C000) to zero out the current values of those bits.
											{ 4, 6,  0xFFC0, 0x0000, 0x003F, 0xFFFF } };// Note that all the masks are ten consecutive set bits.

        private static int StorageSizeForDigits(int numDigits)
        {
            //Every three digits requires 10 bits.
            int numBits = ((numDigits / 3) + 1) * 10;
            //Translate this into a number of ushorts.
            // (Note that we add an extra byte to make things easier 
            //  because chunks can span two ushorts).
            return (numBits / 16) + 2;
        }

        private void InitBigIntFromString(string initialValue)
        {
            if (initialValue == null)
            {
                throw new ArgumentNullException("initialValue");
            }

            if (!Regex.IsMatch(initialValue, "^[-+]?([0-9])+$"))
                throw (new ArgumentException("Value must be a valid integer", "initialValue"));

            if (_initialCapacity == 0 || _bitblock == null)
            {
                _initialCapacity = StorageSizeForDigits(initialValue.Length);
                _bitblockArraySize = _initialCapacity;
                _bitblock = new ushort[_bitblockArraySize];
            }

            SetToEmpty();

            if (initialValue.StartsWith("-"))
            {
                _sign = (short)-1;
                initialValue = initialValue.Remove(0, 1);
            }
            else
            {
                _sign = (short)1;
            }

            int currStringPos, currChunkLength;
            if (initialValue.Length <= 3)
            {
                currStringPos = 0;
                currChunkLength = initialValue.Length;
            }
            else
            {
                currStringPos = initialValue.Length - 3;
                currChunkLength = 3;
            }
            do
            {
                ushort nextChunk = 0;
                for (int i = currChunkLength - 1, j = 1; i >= 0; i--, j *= 10)
                {
                    nextChunk += (ushort)(j * Convert.ToUInt16(initialValue[currStringPos + i] - '0'));
                }
                AppendChunk(nextChunk);

                currStringPos -= 3;
                if (currStringPos < 0)
                {
                    currChunkLength = 3 + currStringPos;
                    currStringPos = 0;
                }
            } while (currChunkLength > 0);
            AfterUpdate();
        }

        private void AppendChunk(ushort threeDigitValue)
        {	//adds a new chunk (3 digit number) as the most significant chunk
            int blockNum = _numChunks / 8; //each block holds 8 chunks.
            int blockOffset = _numChunks - (blockNum * 8);
            ushort startByte = mask[blockOffset, 0];
            ushort startBitWithinStartByte = mask[blockOffset, 1];
            int destStartIndex = blockNum * 5 + startByte; //each block is 5 ushorts (10 bytes) in size.
            ushort maskWithinStartByte = mask[blockOffset, 2];
            ushort maskWithinSecondByte = mask[blockOffset, 3];
            uint valueToMask = (uint)threeDigitValue << startBitWithinStartByte;
            ushort startByteMaskComplement = mask[blockOffset, 4];    //used to zero out the blocks 
            ushort secondByteMaskComplement = mask[blockOffset, 5];  // we are about to replace

            ushort maskedValueInStartByte = (ushort)(valueToMask & maskWithinStartByte);
            ushort maskedValueInSecondByte = (ushort)((valueToMask >> 16) & maskWithinSecondByte);

            if (destStartIndex >= (_bitblockArraySize - 1))
            {
                //We have reached the limit of the current array allocation, so allocate some more.
                _bitblockArraySize += ARRAY_ALLOC_SIZE;
                Array.Resize<ushort>(ref _bitblock, _bitblockArraySize);
            }

            _bitblock[destStartIndex] = (ushort)((_bitblock[destStartIndex] & startByteMaskComplement) | maskedValueInStartByte);
            _bitblock[destStartIndex + 1] = (ushort)((_bitblock[destStartIndex + 1] & secondByteMaskComplement) | maskedValueInSecondByte);
            _numChunks++;
        }

        private short GetChunkAbsolute(int chunkIndex)
        {
            if (chunkIndex >= NumChunks)
                return 0;

            int blockNum = chunkIndex / 8;
            int blockOffset = chunkIndex - (blockNum * 8);
            ushort startByte = mask[blockOffset, 0];
            ushort startBitWithinStartByte = mask[blockOffset, 1];
            ushort maskWithinStartByte = mask[blockOffset, 2];
            ushort maskWithinSecondByte = mask[blockOffset, 3];

            ushort val1 = (ushort)(_bitblock[blockNum * 5 + startByte] & maskWithinStartByte);
            ushort val2 = (ushort)(_bitblock[blockNum * 5 + startByte + 1] & maskWithinSecondByte);
            return (short)((val1 >> startBitWithinStartByte) | (val2 << (16 - startBitWithinStartByte)));
        }

        private short GetChunk(int chunkIndex)
        {
            if (_sign == 1)
                return GetChunkAbsolute(chunkIndex);
            else
                return (short)-GetChunkAbsolute(chunkIndex);
        }

        private void AfterUpdate()
        {
            while (_numChunks > 0 && GetChunk(_numChunks - 1) == 0)
                _numChunks--; //Remove zero chunks from LHS

            if (_numChunks == 0)
            {
                SetToEmpty();
            }
            else
            {
                _numDigits = (_numChunks - 1) * 3;
                short lastChunk = GetChunk(_numChunks - 1);
                if (_sign == -1) lastChunk = (short)-lastChunk;
                if (lastChunk > 99)
                    _numDigits += 3;
                else if (lastChunk > 9)
                    _numDigits += 2;
                else
                    _numDigits++;
            }
        }

        /// <summary>
        /// Compares the absolute values of two BigInts
        /// </summary>
        /// <returns>1 if |a| > |b|, 0 if |a| == |b|, -1 if |a| is less than |b|</returns>
        private static short CompareMagnitudes(BigInt a, BigInt b)
        {
            if (a.IsZero() && b.IsZero())
                return 0;

            if (a.NumDigits > b.NumDigits)
            {	//a has more digits than b so it must be bigger
                return (short)1;
            }
            else if (a.NumDigits < b.NumDigits)
            {	//a has fewer digits than b so it must be smaller
                return (short)-1;
            }
            else
            {
                short aChunk, bChunk;
                for (int i = a.NumChunks - 1; i >= 0; i--)
                {
                    aChunk = a.GetChunkAbsolute(i);
                    bChunk = b.GetChunkAbsolute(i);
                    if (aChunk < bChunk)
                        return -1;
                    else if (aChunk > bChunk)
                        return 1;
                }
                //they must be equal
                return 0;
            }
        }

        private bool IsInitialized()
        {
            return (_bitblock != null) && (_bitblock.Length > 0);
        }

        private void EnsureInitialized()
        {
            if (!IsInitialized())
                SetToEmpty();
        }

        private void SetToEmpty()
        {
            _sign = 1;
            _numChunks = 0;
            _numDigits = 0;
        }

        private bool IsZero()
        {
            if (_numChunks > 1)
                return false;
            else if (!IsInitialized())
                return true;
            else
                return (_bitblock[0] == 0);
        }

        private static int MaxNumChunks(BigInt a, BigInt b)
        {
            if (a.NumChunks > b.NumChunks)
                return a.NumChunks;
            else
                return b.NumChunks;
        }

        private static int MinNumChunks(BigInt a, BigInt b)
        {
            if (a.NumChunks < b.NumChunks)
                return a.NumChunks;
            else
                return b.NumChunks;
        }

        private static BigInt DivideAndConquerMultiply(BigInt a, BigInt b)
        {
            //faster divide-and-conquer multiplication, called by operator* when a and b are
            //large.  Do not call directly.

            int numChunks = MaxNumChunks(a, b);
            if (MinNumChunks(a, b) < D_AND_C_THRESHOLD)
                return (a * b);

            if ((numChunks & 1) == 1)  // if numChunks is odd, add 1
                numChunks++;

            int N = numChunks / 2;
            int Ndigits = N + N + N; // N chunks = 3N digits
            //set a0,a1,b0,b1 such that a = (1000^N)*A1 + A0, b = (1000^N)*B1 + B0
            //then a*b = (1000^(2N) + 1000^N)A1B1 + 1000^N(A1-A0)(B0-B1) + (1000^N + 1)A0B0

            int capacity = StorageSizeForDigits(a.NumDigits + b.NumDigits);
            BigInt a0 = new BigInt(capacity, 0);
            BigInt a1 = new BigInt(capacity, 0);
            BigInt b0 = new BigInt(capacity, 0);
            BigInt b1 = new BigInt(capacity, 0);
            for (int i = 0; i < N; i++)
            {
                a0.AppendChunk((ushort)a.GetChunkAbsolute(i));
                a1.AppendChunk((ushort)a.GetChunkAbsolute(i + N));
                b0.AppendChunk((ushort)b.GetChunkAbsolute(i));
                b1.AppendChunk((ushort)b.GetChunkAbsolute(i + N));
            }

            a0.AfterUpdate(); //TODO: get rid of these? and call result.AfterUpdate?
            a1.AfterUpdate();
            b0.AfterUpdate();
            b1.AfterUpdate();

            BigInt part1 = DivideAndConquerMultiply(a1, b1);
            BigInt part2 = DivideAndConquerMultiply(a1 - a0, b0 - b1);
            BigInt part3 = DivideAndConquerMultiply(a0, b0);

            BigInt result = (part1 << 2 * Ndigits) + (part1 << Ndigits) + (part2 << Ndigits) + (part3 << Ndigits) + part3;
            result._sign = (short)(a.Sign * b.Sign); //-ve * -ve == +ve, etc
            return result;
        }

        private static void DivAndMod(DivModOperationType operationType, BigInt a, BigInt b, out BigInt remainder, out BigInt result)
        // sets <result> to the result of dividing a by b, and sets <remainder> to the remainder when
        // a is divided by b
        {
            if (b.IsZero())
                throw new DivideByZeroException();

            if (CompareMagnitudes(a, b) < 0)  // if a is less than b then it's a no-brainer
            {
                if (operationType != DivModOperationType.DivideOnly)
                    remainder = a;
                else
                    remainder = 0;
                result = 0;
                return;
            }

            if (a.NumChunks <= 3)
            {	//a, b small - just use machine arithmetic
                remainder = 0;
                int intA = Convert.ToInt32(a.ToString());
                int intB = Convert.ToInt32(b.ToString());
                if (operationType != DivModOperationType.DivideOnly)
                    remainder = intA % intB;
                if (operationType != DivModOperationType.ModulusOnly)
                    result = intA / intB;
                else
                    result = 0;
                return;
            }

            result = new BigInt(a.Capacity, 0);

            BigInt removal, resultStore = new BigInt(a.Capacity, 0);

            short resultSign = (short)(a.Sign * b.Sign);
            short bSign = b.Sign;
            ushort trialDiv;
            short comparison;
            int numBdigits = b.NumDigits;

            remainder = a;
            remainder._sign = 1;
            b._sign = 1;					// work with positive numbers

            int bTrial = 0;
            if (b.NumChunks == 1)
                bTrial = b.GetChunkAbsolute(b.NumChunks - 1);
            else
                bTrial = b.GetChunkAbsolute(b.NumChunks - 1) * 1000 + b.GetChunkAbsolute(b.NumChunks - 2);

            int bTrialDigits = (int)Math.Floor(Math.Log10(bTrial)) + 1;
            int thisShift = 0, lastShift = -1;


            while (remainder >= b)
            {
                int lastRemainderDigits = remainder.NumDigits;
                int remTrial;
                short remMostSigChunk = remainder.GetChunkAbsolute(remainder._numChunks - 1);
                //remTrial is formed by taking the most significant 1, 2 or 3 chunks of remainder;
                // take the minimum number of chunks needed to make remTrial bigger than bTrial.
                if (remMostSigChunk >= bTrial)
                {
                    remTrial = remMostSigChunk;
                }
                else
                {
                    remTrial = remMostSigChunk * 1000 + remainder.GetChunkAbsolute(remainder.NumChunks - 2);
                    if (remTrial < bTrial)
                        remTrial = (remTrial * 1000) + remainder.GetChunkAbsolute(remainder.NumChunks - 3);
                    //now remTrial should be >= bTrial.  remTrial == bTrial is the nasty special case that produces trialDiv == 1.
                }

                trialDiv = (ushort)(remTrial / bTrial); // this is our guess of the next quotient chunk
                removal = b.ShortMultiply(trialDiv);
                int remTrialDigits = (int)Math.Floor(Math.Log10(remTrial)) + 1;
                thisShift = remainder.NumDigits - (remTrialDigits - bTrialDigits) - numBdigits;
                removal = removal << thisShift;

                // normally, the required shift drops by three (the number of digits in a chunk) with 
                // each loop iteration.  But if the result contains a 000 chunk in the middle, we 
                // will notice a drop in shift of more than 3.
                if (operationType != DivModOperationType.ModulusOnly)
                    for (int i = 0; i < lastShift - thisShift - 3; i += 3)
                        resultStore.AppendChunk(0);

                // our guess of the next quotient chunk might be too high (but not by more than two);
                // adjust it down if necessary
                BigInt bShifted = 0;
                bool bShiftedSet = false;
                do
                {
                    comparison = Compare(removal, remainder);
                    if (comparison > 0)
                    {
                        trialDiv--;
                        if (trialDiv == 0)
                        {
                            //This is the nasty special case.  I think that the first three cases can 
                            // never happen.  Effectively what happens is that have guessed 1000 (through
                            // trialDiv = 1 and thisShift >= 3) and found that it is one high so we 
                            // reduce it to 999 (through trialDiv = 999 and thisShift -= 3).
                            switch (thisShift)
                            {
                                case 0: //This should never happen
                                    break;
                                case 1:
                                    trialDiv = 9;
                                    thisShift = 0;
                                    break;
                                case 2:
                                    trialDiv = 99;
                                    thisShift = 0;
                                    break;
                                default:
                                    trialDiv = 999;
                                    thisShift -= 3;
                                    break;
                            }
                        }
                        if (!bShiftedSet)
                        {
                            bShiftedSet = true;
                            bShifted = b << thisShift;
                        }
                        removal -= bShifted;
                    }
                } while (comparison > 0);

                lastShift = thisShift;

                remainder -= removal;
                if (operationType != DivModOperationType.ModulusOnly) resultStore.AppendChunk(trialDiv);
            }

            b._sign = bSign; // put back b's sign

            if (operationType != DivModOperationType.DivideOnly)
            {
                remainder._sign = a.Sign; // sign of mod = sign of a
                remainder.AfterUpdate();
            }

            if (operationType != DivModOperationType.ModulusOnly)
            {
                for (int i = 3; i <= thisShift; i += 3)
                    resultStore.AppendChunk(0);
                //resultStore now holds the quotient chunks in reverse order.  Flip them and return.
                for (int i = resultStore.NumChunks - 1; i >= 0; i--)
                    result.AppendChunk((ushort)resultStore.GetChunkAbsolute(i));
                result._sign = resultSign;
                result.AfterUpdate();
            }
        }

        #endregion
    }

    public static class CodeJamExtensions
    {
        public static IEnumerable<string> ReadDataLines(this StreamReader reader)
        {
            int lineCount = reader.ReadLine().ToInt32();
            return reader.ReadLines(lineCount);

        }

        public static IEnumerable<string> ReadLines(this StreamReader reader, int lineCount)
        {
            for (int i = 0; i < lineCount; i++)
            {
                yield return reader.ReadLine();
            }
        }

        public static int ToInt32(this string str)
        {
            return int.Parse(str);
        }

        public static List<string> SplitSpace(this string str)
        {
            return str.Split(' ').ToList();
        }

        private static int caseIndex = 0;

        public static void WriteCaseOutput(this StreamWriter writer, params object[] values)
        {
            writer.Write("Case #{0}:", caseIndex + 1);
            foreach (var val in values)
            {
                writer.Write(" ");
                writer.Write(val);
            }
            writer.WriteLine();
            caseIndex++;
        }

    }

    class Program
    {
        static string ToOutputFileName(string fileName)
        {
            return Path.GetFileNameWithoutExtension(fileName) + ".out";
        }

        private static BigInt getGreatestDivisor(BigInt a, BigInt b)
        {
            BigInt more = a;
            BigInt less = b;
            if (more < less)
            {
                more = b;
                less = a;
            }
            BigInt remainder = more;
            while (remainder > 0)
            {
                remainder = more % less;
                more = less;
                less = remainder;
            }
            return more;
        }

        private static BigInt calculate(IEnumerable<BigInt> ts)
        {
            Dictionary<BigInt, int> d = new Dictionary<BigInt, int>();
            foreach (var item in ts)
            {
                d[item] = 0;
            }

            var sortedList = d.Keys.ToList();
            sortedList.Sort((x, y) =>
            {
                if (x > y) return 1;
                else if (x < y) return -1;
                else return 0;
            });

            BigInt minDiff = sortedList[sortedList.Count - 1];
            int minIdx = -1;
            var diffList = new List<BigInt>();
            for (int i = 0; i < sortedList.Count - 1; i++)
            {
                var less = sortedList[i];
                var more = sortedList[i + 1];
                var diff = (more - less);
                if (minDiff > diff) minDiff = diff;
                diffList.Add(diff);
            }

            var gd = minDiff;
            for (int i = 0; i < diffList.Count; i++)
            {
                gd = getGreatestDivisor(gd, diffList[i]);
                if (gd == 1) break;
            }


            BigInt remainder = sortedList[0] % gd;
            if (remainder == 0) return 0;
            else return gd - remainder;
        }

        static void Main(string[] args)
        {
            string inputFileName = args[0];
            var reader = new StreamReader(inputFileName);
            int caseCount = reader.ReadLine().ToInt32();
            var writer = new StreamWriter(ToOutputFileName(inputFileName));
            for (int i = 0; i < caseCount; i++)
            {
                var values = reader.ReadLine().SplitSpace();
                values.RemoveAt(0);
                var intValues = values.Select(val => new BigInt(val));
                writer.WriteCaseOutput(calculate(intValues).ToString());
            }
            reader.Close();
            writer.Close();

            // show explorer to access output file
            Process.Start("Explorer", Environment.CurrentDirectory);
        }
    }
}
