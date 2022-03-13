<script type="text/javascript" src="http://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>
<script type="text/x-mathjax-config">
    MathJax.Hub.Config({ tex2jax: {inlineMath: [['$', '$']]}, messageStyle: "none" });
</script>

[toc]
# Dynamic Programming
## 悬线法
用于解决网格中最大矩形的算法.
# Graph
## 前向星存图
## 最短路
多源最短路：Floyed;
单源最短路：Bellman-Ford,SPFA,Dijkstra.
### FLoyed
$O(n^3)$ 比较暴力.
### Bellman-Ford
$O(mn)$ 比较暴力.
### SPFA
队列优化的Bellman-Ford算法.复杂度不稳定.
### Dijkstra
不断取出离顶点最近而没有被访问过的点，松弛它和它能到达的所有点.利用优先队列（堆）可在$O(m\log m)$的时间跑完最短路.
# Data Structure
## Segment Tree
$O(\log n)$的时间内实现区间修改和区间查询.
