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
## Hungarian Algorithm
解决二分图的最大匹配数和最小点覆盖数.König定理:一个二分图中的最大匹配数等于这个图中的最小点覆盖数.

# Data Structure
## Segment Tree
$O(\log n)$的时间内实现区间修改和区间查询.
## Chtholly Tree
线性复杂度实现区间更改、区间求和、取kth元素等操作，利用`std::set<Node>`实现，重点操作是暴力的`split(ll pos)`.
## 分块
$O(\sqrt{n})$暴力.
## BST
Bineary Search Tree
### Scapegoat Tree
use `flatten()` and `rebuild` to balance BST.
### Heap
# String
## KMP
利用Paritial Matched Table解决匹配时的浪费（待更新常数优化）
## Trie
利用树状结构维护字符串.
