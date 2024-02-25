# ブラシレスモーターのためのリポジトリ
ブラシレスモーターの制御基板で使用するコードを書くと良いと思います。

## C610とは
そもそもC610とはM2006というロボマスモーター専用の制御基板のことです。が、以降C610はブラシレスモーターの制御基板全般のことをいうことにしようと思うので、**ロボマスの**C610関連のコード類は**Robomas**_C610となります。

## リポジトリの構成
このディレクトリの構成は以下の通り。  
- *基板名(example)*
  - [sample1.c](C610/基板名(example)/sample1.c)
  - [sample2.py](C610/基板名(example)/sample2.py)

- *Robomas_C610*
  - [Robomas_C610_test.ino](C610/Robomas_C610/Robomas_C610_test.ino)

## Robomas_C610
#### [Robomas_C610_test.ino](C610/Robomas_C610/Robomas_C610_test.ino)
M2006を回すためのサンプルコードです。
