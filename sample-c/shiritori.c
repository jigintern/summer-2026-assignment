// shiritori.c
//
// しりとりCLI（Step 5 相当）
// 直前の単語の末尾3バイトと、入力された単語の先頭3バイトを比較し、
// 一致する場合だけ単語を更新する。
// 「ん」での終了・重複検出・リセット機能は未実装。
//
// ビルド: gcc shiritori.c -o shiritori
// 実行:   ./shiritori

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
