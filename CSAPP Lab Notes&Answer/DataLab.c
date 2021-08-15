/*题干：
 * bitXor - x^y using only ~ and &
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */

/*答案：
 * x&y的bit位上都为1时对应bit位为1，~(x&y)为对应的bit位是0则比特位值为1
 * ~x&~y的bit位上当原数都为0时对应bit位为1，~(~x&~y)为对应bit位有一个为1则值为1
 * 将两个表达式进行与运算，得出只有一个bit位为1时才返回1的结果
 */
int bitXor(int x, int y) {

    return ~(~x & ~y) & ~(x & y);
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/*
 * tmin - return minimum two's complement integer
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */

/*答案：
* 二进制补码最大为1000 ... 0000因此将1右移31位就行
*/
int tmin(void) {
	return 1 << 31;
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/*题干：
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */

 /*答案：
 * 二进制补码最大值为0111 .... 1111
 *最大值取反和加1都为1000 .... 0000，因此可以用异或算出~x ^ (x+1)，得到的应该为0000 .... 0000。！运算得到1
 * 这里要注意，另一个符合这个例子的数字为-1，因此要排除-1：
 *   -1的表达式为1111 .... 1111，因此取反!运算后会返回1。再!获得0
 */
int isTmax(int x) {
	return !(~x ^ (x + 1)) & !!(~x);
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/*题干：
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */

 /*答案：
 *  当奇数位全为1其他位为0时，二进制表示为1010 .... 1010。16进制表示为0xAAAAAAAA
 * 这时我们可以将数x与其进行与运算，这样就只保留下了x上的奇数位，舍掉了偶数位。
 * 然后判断x==0xAAAAAAAA，这里的操作可以用!(x^0xAAAAAAAA)代替
 */
int allOddBits(int x) {
    int a = (0xAA << 8) | 0xAA;
    int max = a << 16 | a;
    return !((x & max) ^ max);
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/*题干：
 * negate - return -x
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */

 /*答案：
 * 对一个数取反就是~x然后+1
 */
int negate(int x) {
	return ~x + 1;
}
