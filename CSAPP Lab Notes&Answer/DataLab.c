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
