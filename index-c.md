<link href="https://cdnjs.cloudflare.com/ajax/libs/github-markdown-css/5.8.1/github-markdown.css" rel="stylesheet"></link>
<style>
  img {
    width: 80%;
    max-width: 800px;
    margin-left: 5%;
    outline: solid #4d4d4d;
  }
  /* コードブロック（```で囲まれた複数行コード）の視認性を強化 */
  pre {
    background-color: #f3f4f6 !important;
    border: 1px solid #d0d7de !important;
    border-left: 4px solid #4d4d4d !important;
    border-radius: 6px !important;
    box-shadow: 0 1px 2px rgba(0, 0, 0, 0.06);
    padding: 14px 16px !important;
  }
  pre code {
    background-color: transparent !important;
    padding: 0 !important;
    font-size: 0.95em;
    line-height: 1.55;
  }
  /* インラインコード（文中の `code`）の視認性を強化 */
  :not(pre) > code {
    background-color: #eef1f4 !important;
    border: 1px solid #d8dde3;
    border-radius: 4px;
    padding: 0.15em 0.35em !important;
    font-size: 0.9em;
  }
  /* ダークモード時の上書き（markdown-to-html-cliのdata-color-mode属性に追従） */
  [data-color-mode="dark"] pre {
    background-color: #0d1117 !important;
    border: 1px solid #30363d !important;
    border-left: 4px solid #8b949e !important;
    box-shadow: 0 1px 2px rgba(0, 0, 0, 0.4);
  }
  [data-color-mode="dark"] pre code {
    color: #e6edf3;
  }
  [data-color-mode="dark"] :not(pre) > code {
    background-color: rgba(110, 118, 129, 0.4) !important;
    border: 1px solid #30363d;
    color: #e6edf3;
  }
  [data-color-mode="dark"] img {
    outline-color: #8b949e;
  }
</style>

# jig.jp サマーインターンシップ 選考課題(SABERAコース)

## はじめに

今回のインターンシップの選考課題では、ターミナル上で動作する「しりとりアプリ」をC言語で実装して提出していただきます。  
コンパイラの種類（gcc / clang）に制限はありませんので、お手元の環境で取り組んでください。

AIの活用について制限はありません、積極的に活用してください。  
ただし、後述の通り、使用した場合は「どの部分にどのように活用したか」を README に記入してください。

## 課題内容

ターミナル上で動作する「しりとりアプリ」をC言語かC++で実装して提出してください。

この資料ではC言語での実装についてまとめています。参考にしてください。

### 提出方法について

ソースコード一式と README を掲載した GitHub リポジトリのリンクを以下の Google フォームから提出してください。  

README.mdは以下の仕様を満たすよう作成してください。
これ以外の内容が含まれていても問題ありません。

- Markdown を使用して作成すること
- ビルド方法と実行方法（例: `gcc shiritori.c -o shiritori && ./shiritori`）
- 動作の様子が分かるスクリーンショット
- 実装した機能の詳細な説明
- 参考にしたWebサイト
- AIを使った場合、どのように活用したか

**課題提出用Googleフォーム**  
[https://forms.gle/v2rkvJUsamCrWWvS7](https://forms.gle/v2rkvJUsamCrWWvS7)

### 仕様

まず、以下の仕様を満たすように実装してください。

- 直前の単語を、表示できるようにする
- 任意の単語を、入力できるようにする
- 直前の単語の末尾と、入力した単語の先頭を比較して、同じ場合だけ単語を更新する。違う場合は、エラーを表示する
- 末尾が「ん」で終わる単語が入力されたら、ゲームを終了する
- 過去に使用した単語が入力されたら、ゲームを終了する
- ゲーム中や終了後に、最初からやり直せるリセット機能をつける

追加で、便利・面白いと思う任意の機能を考えて、最低2つ以上実装してください。以下に例を示します。

- 最初の単語がランダムに決まるようにする
- 一文字のものや絵文字等、しりとりとして不適切な単語は入力できないようにする
- ひらがな以外は入力できないようにする
- 実在しない単語は入力できないようにする
- しりとりの単語の履歴を表示できるようにする
- 複数のユーザーが対戦できるようにする

## Step 0. GitHubアカウントの作成

> GitHubアカウント作成後、数日経過しなければ使用できない機能もあるため、早めに登録することをおすすめします。

作成したCLIアプリの提出等に必要なため、GitHubアカウントを作成しましょう。  
以下のWebサイトからアカウント登録を行ってください。

> 既にアカウントをお持ちの方は、そちらのアカウントを使用していただいて構いません

[https://github.com/](https://github.com/)

## Step 1. VSCodeのインストール

### Visual Studio Codeとは

Microsoftが提供しているソースコードエディタです。VSCodeとも呼ばれます。  
開発に必要な機能の多くを搭載しており、プラグインの開発も企業・個人問わず行われているので、特に拘りが無ければインストールをおすすめします。

既にお気に入りのエディタがある場合は、インストールせずに進めていただいても構いません。

### Visual Studio Codeのインストール

公式サイトの説明に従い、Visual Studio Codeをインストールしてみましょう。

[https://code.visualstudio.com/](https://code.visualstudio.com/)

ご自身のOSに合わせたものをダウンロードして、インストールしましょう。

### ターミナルの準備

VSCode上で、Ctrl(Macの場合はCmd)とJを押すことで、下部のパネルを表示を切り替えることができます。  
パネル内にある「ターミナル」からコマンドを実行することができるため、コマンドの実行はこちらを使用してください。

WindowsのPowerShellやMacのターミナルを使用しても構いません。

## Step 2. Cコンパイラのインストール

C言語のソースコードをコンパイル（実行可能ファイルに変換）するために、Cコンパイラをインストールします。

### macOS の場合

macOS では Xcode Command Line Tools をインストールすることで、`clang`（C/C++コンパイラ）が使えるようになります。  
ターミナルを開いて、以下のコマンドを実行してください。

```sh
xcode-select --install
```

インストールダイアログが表示されるので、案内に従ってインストールを完了させます。

完了したら、以下のコマンドでバージョン情報が表示されることを確認しましょう。

```sh
# 入力
cc --version

# 出力例
Apple clang version 17.0.0 (clang-1700.6.3.2)
Target: arm64-apple-darwin25.3.0
Thread model: posix
InstalledDir: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin
```

> このドキュメントでは `gcc` というコマンド名で記載していますが、macOS では `gcc` を実行しても `clang` が呼び出されるようになっているため、そのまま `gcc` を使って構いません。

### Windows（WSL）の場合

Windows では WSL（Windows Subsystem for Linux）をインストールし、その中で `gcc` を使用します。

1. PowerShell を **管理者として実行** し、以下のコマンドを実行します。

```sh
wsl --install
```

2. インストールが完了したら、PCを再起動します。
3. 再起動後、スタートメニューから「Ubuntu」を起動します。初回起動時にユーザー名とパスワードの設定が求められるので入力します。
4. Ubuntu のターミナルで、以下のコマンドを実行して `gcc` をインストールします。

```sh
sudo apt update
sudo apt install build-essential
```

> `build-essential` は、`gcc` を含む C/C++ の開発に必要なツール一式をまとめたパッケージです。

5. インストールが完了したら、以下のコマンドでバージョン情報が表示されることを確認しましょう。

```sh
# 入力
gcc --version

# 出力例
gcc (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0
Copyright (C) 2021 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even to the extent permitted by law.  FOR A PARTICULAR PURPOSE.
```

> 以降のコマンド操作は、Windows ユーザーの場合は WSL 上の Ubuntu ターミナルで行ってください。

## Step 3. CでHello World

Hello World を出力するプログラムを作って実行してみましょう。

1. 空のフォルダを作成し、その中に `hello.c` を作成して以下の内容を書き込みます。

```c
// hello.c
#include <stdio.h>

int main(void) {
    printf("Hello, World!\n");
    return 0;
}
```

2. ターミナルで `hello.c` のあるフォルダに移動し、以下のコマンドでコンパイルします。

```sh
gcc hello.c -o hello
```

> `-o hello` は出力ファイル名の指定です。指定しないと `a.out` というファイル名で出力されます。

3. コンパイルが成功すると、`hello` という実行可能ファイルが作成されます。実行してみましょう。

```sh
./hello

# Hello, World!
```

`Hello, World!` と表示されればOKです！

> Topic: `printf` の中身を書き換えて再コンパイル・実行してみましょう。ソースを変更したら再コンパイルが必要なことが C 言語の特徴です。

## Step 4. 標準入力を受け取ってみよう

ユーザーからキーボード入力を受け取り、それをそのまま表示するプログラムを作ってみます。

1. `shiritori.c` を作成して、以下の内容を書き込みます。

```c
// shiritori.c
#include <stdio.h>
#include <string.h>

#define MAX_WORD_LENGTH 256

int main(void) {
    char input[MAX_WORD_LENGTH];

    printf("単語を入力してください > ");

    // 標準入力から1行受け取る
    if (fgets(input, sizeof(input), stdin) == NULL) {
        return 0;
    }

    // 末尾の改行を削除
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    printf("入力された単語: %s\n", input);
    return 0;
}
```

2. コンパイルして実行します。以降は同じコマンドを何度も使うので、ターミナルの上下キーで履歴を辿ると便利です。

```sh
gcc shiritori.c -o shiritori
./shiritori
```

3. 単語を入力して Enter を押し、入力した内容が表示されればOKです！

```
単語を入力してください > りんご
入力された単語: りんご
```

> **Note: 改行の削除について**  
> `fgets` は、Enter キーで入力された改行文字（`\n`）も文字列の末尾に含めます。そのままだと「りんご\n」のような文字列になってしまい、後の処理（末尾と先頭の比較など）で困るので、ここで改行を削除しておきます。

> **Note: UTF-8 と文字列**  
> 日本語の「ひらがな1文字」は、UTF-8 では **3バイト** で表されます。  
> 例えば「り」は `0xE3 0x82 0x8A` の3バイトです。`strlen` は文字数ではなく **バイト数** を返すので、「りんご」の場合は `9`（3文字 × 3バイト）が返ってきます。

## Step 5. しりとり実装(1): 末尾と先頭の比較

直前の単語を保持しておき、入力された単語との「しりとりが成立しているか」を判定します。

UTF-8 ではひらがな1文字が3バイトなので、

- 直前の単語の **末尾3バイト**
- 入力された単語の **先頭3バイト**

を `strncmp` で比較すれば、「末尾と先頭が同じひらがなか」を判定できます。

1. `shiritori.c` を以下の内容に書き換えます。

```c
// shiritori.c
#include <stdio.h>
#include <string.h>

#define MAX_WORD_LENGTH 256

int main(void) {
    // 直前の単語を保持する
    char previous_word[MAX_WORD_LENGTH] = "しりとり";
    char next_word[MAX_WORD_LENGTH];

    printf("しりとりを始めます！\n");
    printf("（終了するには Ctrl+D を押してください）\n\n");

    while (1) {
        printf("前の単語: %s\n", previous_word);
        printf("次の単語を入力してください > ");

        // 標準入力から1行受け取る
        if (fgets(next_word, sizeof(next_word), stdin) == NULL) {
            printf("\nしりとりを終了します。\n");
            break;
        }

        // 末尾の改行を削除
        size_t len = strlen(next_word);
        if (len > 0 && next_word[len - 1] == '\n') {
            next_word[len - 1] = '\0';
            len--;
        }

        // 空入力は無視
        if (len == 0) {
            continue;
        }

        // UTF-8 ではひらがな1文字が3バイトなので、
        // 末尾の3バイトと先頭の3バイトを比較する
        size_t prev_len = strlen(previous_word);
        if (prev_len < 3 || len < 3) {
            printf("エラー: ひらがなを入力してください\n\n");
            continue;
        }

        if (strncmp(previous_word + prev_len - 3, next_word, 3) == 0) {
            // 末尾と先頭が一致したので、直前の単語を更新
            strcpy(previous_word, next_word);
            printf("\n");
        } else {
            printf("エラー: 前の単語に続いていません\n\n");
        }
    }

    return 0;
}
```

2. 再コンパイルして実行してみましょう。

```sh
gcc shiritori.c -o shiritori
./shiritori
```

3. しりとりを進めてみて、繋がる単語は更新され、繋がらない単語にはエラーが表示されればOKです！

```
しりとりを始めます！
（終了するには Ctrl+D を押してください）

前の単語: しりとり
次の単語を入力してください > りんご

前の単語: りんご
次の単語を入力してください > ごりら

前の単語: ごりら
次の単語を入力してください > らっぱ

前の単語: らっぱ
次の単語を入力してください > みかん
エラー: 前の単語に続いていません

前の単語: らっぱ
次の単語を入力してください >
```

> Topic: Step 5 までを実装したサンプルが、[こちら](https://github.com/jigintern/summer-2026-assignment/blob/main/sample-c/shiritori.c)にあります。  
> 詰まったら参考にしてみてください。

## Step 6. しりとり実装(2): 「ん」終了 + 履歴管理

仕様にある「『ん』で終わる単語が入力されたら終了」と「過去に使用した単語が入力されたら終了」を実装します。

### 「ん」で終わるかの判定

UTF-8 で「ん」は `0xE3 0x82 0x93` の3バイトです。  
入力された単語の末尾3バイトがこの並びと一致すれば「ん」で終わっていると判定できます。

### 単語の履歴管理

これまでは直前の単語1つだけを保持していましたが、過去全ての単語との重複チェックが必要になるので、二次元配列を使って履歴を保持するように変更します。

1. `shiritori.c` を以下の内容に書き換えます。

```c
// shiritori.c
#include <stdio.h>
#include <string.h>

#define MAX_WORD_LENGTH 256
#define MAX_HISTORY 100

int main(void) {
    // 単語の履歴をまとめて保持する
    char history[MAX_HISTORY][MAX_WORD_LENGTH];
    int history_count = 0;
    char next_word[MAX_WORD_LENGTH];

    // 初期単語をセット
    strcpy(history[0], "しりとり");
    history_count = 1;

    printf("しりとりを始めます！\n");
    printf("（終了するには Ctrl+D を押してください）\n\n");

    while (1) {
        const char *previous_word = history[history_count - 1];
        printf("前の単語: %s\n", previous_word);
        printf("次の単語を入力してください > ");

        if (fgets(next_word, sizeof(next_word), stdin) == NULL) {
            printf("\nしりとりを終了します。\n");
            break;
        }

        size_t len = strlen(next_word);
        if (len > 0 && next_word[len - 1] == '\n') {
            next_word[len - 1] = '\0';
            len--;
        }
        if (len == 0) {
            continue;
        }

        size_t prev_len = strlen(previous_word);
        if (prev_len < 3 || len < 3) {
            printf("エラー: ひらがなを入力してください\n\n");
            continue;
        }

        // 末尾と先頭の比較
        if (strncmp(previous_word + prev_len - 3, next_word, 3) != 0) {
            printf("エラー: 前の単語に続いていません\n\n");
            continue;
        }

        // 「ん」で終わるかチェック
        // UTF-8 で「ん」は 0xE3 0x82 0x93
        if ((unsigned char)next_word[len - 3] == 0xE3 &&
            (unsigned char)next_word[len - 2] == 0x82 &&
            (unsigned char)next_word[len - 1] == 0x93) {
            printf("\n「%s」は「ん」で終わるため、ゲーム終了です！\n", next_word);
            break;
        }

        // 重複チェック
        int duplicated = 0;
        for (int i = 0; i < history_count; i++) {
            if (strcmp(history[i], next_word) == 0) {
                duplicated = 1;
                break;
            }
        }
        if (duplicated) {
            printf("\n「%s」は既に使われた単語です。ゲーム終了です！\n", next_word);
            break;
        }

        // 履歴に追加
        if (history_count >= MAX_HISTORY) {
            printf("\n履歴が一杯になりました。ゲーム終了です！\n");
            break;
        }
        strcpy(history[history_count], next_word);
        history_count++;
        printf("\n");
    }

    return 0;
}
```

2. 再コンパイルして実行し、「ん」で終わる単語や過去に出た単語を入力したときにゲームが終了することを確認しましょう！

```
前の単語: ごりら
次の単語を入力してください > らん

「らん」は「ん」で終わるため、ゲーム終了です！
```

## Step 7. しりとり実装(3): リセット機能

ゲーム中や終了後に、最初からやり直せるようにします。  
ここでは、ユーザーが `reset` と入力した場合に履歴をクリアして最初の状態に戻すようにしてみましょう。

1. `shiritori.c` のメインループ冒頭付近に、リセット処理を追加します。

```diff
          if (len == 0) {
              continue;
          }
  
+         // リセットコマンド
+         if (strcmp(next_word, "reset") == 0) {
+             strcpy(history[0], "しりとり");
+             history_count = 1;
+             printf("\nリセットしました。最初からやり直します。\n\n");
+             continue;
+         }
+ 
          size_t prev_len = strlen(previous_word);
```

> **Note: ゲーム終了後のリセットについて**  
> 上記の実装では、ゲームが終了する（`break` する）と while ループを抜けてしまうため、終了後のリセットができません。終了後もリセットできるようにしたい場合は、`break` の代わりにフラグ変数で状態管理する、あるいは終了後に「もう一度遊びますか？」の選択肢を出すなど、ご自身で工夫してみてください。

2. 再コンパイルして、`reset` と入力したときに最初の状態に戻ることを確認しましょう！

```
前の単語: りんご
次の単語を入力してください > reset

リセットしました。最初からやり直します。

前の単語: しりとり
次の単語を入力してください >
```

## Step 8. GitHubリポジトリを作って提出物を準備しよう

作成したCLIアプリを GitHub リポジトリに保存し、コードを公開しましょう。

GitHub は、Git のリポジトリをインターネット上で管理するためのサービスです。リポジトリをアップロードしておくことで、複数人での開発時のソースコードの共有、ソースコードのバックアップ、ご自身の実績の公開の場として、などの効果を期待できます。

### リポジトリの作成

1. GitHub の新規リポジトリを作りましょう。[https://github.com/new](https://github.com/new) にアクセスして、任意のリポジトリ名を入力、公開状態は「Public」としてください。他の設定は触らなくて大丈夫です。

![](./imgs/10_github-new-project.png)

2. 以下のような画面になれば、リポジトリの完成です。任意の方法で、GitHub にソースコードをプッシュしてみましょう。CUI で操作する場合は、GitHub の画面に表示されているコマンドを実行すればOKです。

![](./imgs/11_github-initialize-project.png)

> Topic: コミット、プッシュなど、Gitの操作について軽く調べてみましょう。

## Step 9. おわりに ＋ 実装のヒント

ここまでで、必須仕様を満たすしりとりCLIアプリを実装し、GitHub リポジトリに公開する手順を学びました。

提出は資料冒頭に記載の Google フォームからお願いします。  
必ず、仕様を満たしていることを確認し、`README` を記載しましょう！

### ヒント1: 最初の単語をランダムに決める

固定の「しりとり」ではなく、いくつかの候補からランダムに選びましょう。  
`rand()` と `srand((unsigned int)time(NULL))` を使うと乱数を発生させられます。`<stdlib.h>` と `<time.h>` のインクルードが必要です。

```c
#include <stdlib.h>
#include <time.h>

const char *initial_words[] = { "りんご", "みかん", "ぶどう", "ばなな" };
srand((unsigned int)time(NULL));
int idx = rand() % 4;
strcpy(history[0], initial_words[idx]);
```

### ヒント2: ひらがな以外の入力を弾く

入力された単語のバイト列をチェックし、UTF-8 のひらがなの範囲（U+3040 ～ U+309F）に収まっているかを確認します。  
UTF-8 では、ひらがなは `0xE3 0x81 0x80` ～ `0xE3 0x82 0x9F` のバイト列で表されます。3バイトずつ区切って、それぞれが範囲内かを確認しましょう。

```c
int is_hiragana_only(const char *word, size_t len) {
    if (len % 3 != 0) return 0;
    for (size_t i = 0; i < len; i += 3) {
        unsigned char b0 = (unsigned char)word[i];
        unsigned char b1 = (unsigned char)word[i + 1];
        if (b0 != 0xE3) return 0;
        if (b1 < 0x81 || b1 > 0x82) return 0;
    }
    return 1;
}
```

### ヒント3: 単語の履歴を画面に表示する

終了時だけでなく、入力ごとに「これまでの単語履歴」を表示するようにしてみましょう。`for` ループで `history` 配列を順に `printf` するだけで実装できます。

### ヒント4: 一文字のひらがなを弾く

「ん」を避けるために一文字のひらがな（「あ」「い」など）だけを入力されると、しりとりとしては微妙です。  
入力された単語の長さ（UTF-8 で3バイト以上か）でチェックを入れることで、一文字入力を防げます。  
余裕があれば「拗音（しゃ・しゅ・しょ など）」を含む単語の扱いも考えてみましょう。

### ヒント5: ファイルから単語辞書を読み込む

`fopen` / `fgets` でテキストファイルを読み込み、辞書に載っていない単語は弾く、という実装もできます。「実在しない単語は入力できないようにする」機能の実現につながります。

### ヒント6: 制限時間を設ける

`<time.h>` の `time()` を使い、入力に制限時間を設けてみましょう。`select()` や `poll()` を使うと「タイムアウト付きの標準入力読み取り」も可能です（少し難しい！）。

---

ぜひ自分なりの工夫を加えて、楽しい「しりとりCLI」に仕上げてみてください！
