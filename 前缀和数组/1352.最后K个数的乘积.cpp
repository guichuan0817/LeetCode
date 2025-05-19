#include<iostream>
#include<vector>

using namespace std;

#include <vector>

class ProductOfNumbers {
    // 前缀积数组
    // preProduct[i] / preProduct[j] 就是 [i, j] 之间的元素积
    std::vector<int> preProduct;

public:
    ProductOfNumbers() {
        // 初始化放一个 1，便于计算后续添加元素的乘积
        preProduct.push_back(1);
    }

    void add(int num) {
        if (num == 0) {
            // 如果添加的元素是 0，则前面的元素积都废了
            preProduct.clear();
            preProduct.push_back(1);
            return;
        }
        int n = preProduct.size();
        // 前缀积数组中每个元素
        preProduct.push_back(preProduct[n - 1] * num);
    }

    int getProduct(int k) {
        int n = preProduct.size();
        if (k > n - 1) {
            // 不足 k 个元素，是因为最后 k 个元素存在 0
            return 0;
        }
        // 计算最后 k 个元素积
        return preProduct[n - 1] / preProduct[n - k - 1];
    }
};

int main() {
    ProductOfNumbers pon;
    pon.add(3);
    pon.add(0);
    pon.add(2);
    pon.add(5);
    pon.add(4);

    cout << pon.getProduct(2) << endl; // 20
    cout << pon.getProduct(3) << endl; // 40
    cout << pon.getProduct(4) << endl; // 0

    pon.add(8);
    cout << pon.getProduct(2) << endl; // 32

    return 0;
}