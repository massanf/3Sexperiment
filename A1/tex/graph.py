import matplotlib.pyplot as plt

x = [100, 200, 300, 400, 500]
y = [1, 2, 3, 4, 5]

# グラフを書く
plt.plot(x, y)

# グラフのタイトル
plt.title("x / y")

# x軸のラベル
plt.xlabel("x")

# y軸のラベル
plt.ylabel("y")

# 表示する
plt.show()