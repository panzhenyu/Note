# 斐波那契数列第n项快速算法(page 31 T 1.19)
##Python Code
<pre>
fast_fib = lambda count : _fast_fib(1, 0, 0, 1, count)
_fast_fib = lambda a, b, p, q, count : \
			b if count == 0 else \
			(_fast_fib(a, b, nextP(p, q), nextQ(p, q), int(count/2)) if count&1 == 0 else \
			 _fast_fib((a+b)*q+a*p, b*p+a*q, p, q, count-1))
nextP = lambda p, q : p*p + q*q
nextQ = lambda p, q : q*q + 2*p*q
</pre>

##Test
<pre>
>>> fast_fib(10)
55
>>> fast_fib(1)
1
>>> fast_fib(2)
1
</pre>

##核心思想
将斐波那契数列第n项的推导看作基于p，q两个参数对其第0项(0，1)做n次变换后取前者。将变换记作T(p,q)，利用T(nextP, nextQ)=T^2(p,q)减少变换次数(区别于矩阵快速幂求斐波那契数列，关键在于对nextP与nextQ的推导)。
<pre>
T(p, q)->(a, b) = (a+b)*q+a*p, b*p+a*q
nextP, nextQ = p^2+q^2, q^2+2*p*q
T(p, q)->T(p, q)->(a, b) = T(nextP, nextQ)->(a, b)
</pre>

# 最大公约数欧几里得算法(page 32)
##Python Code
<pre>
gcd = lambda a, b: a if b == 0 else gcd(b, a%b)
</pre>

##Test
<pre>
>>> gcd(8, 4)
4
>>> gcd(8, 2)
2
>>> gcd(206, 40)
2
</pre>

##核心思想
如果r是a/b的余数，那么a与b的最大公约数跟b与r的最大公约数相同。