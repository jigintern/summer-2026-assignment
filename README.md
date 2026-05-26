# jig.jp サマーインターンシップ2026 選考課題

[株式会社jig.jp](https://jig.jp/) のサマーインターンシップ2026 選考課題用のリポジトリです。

「しりとりアプリ」をテーマに、応募コースに合わせて以下いずれかの課題に取り組んでいただきます。

## コース別 課題資料

| コース | 概要 | 資料(GitHub Pages) | ソース |
| --- | --- | --- | --- |
| Webコース | ブラウザ上で動作する「しりとりアプリ」を任意の言語・フレームワークで実装(資料は Deno を使用) | [index.html](https://jigintern.github.io/summer-2026-assignment/) | [index.md](./index.md) |
| SABERAコース | ターミナル上で動作する「しりとりアプリ」を C / C++ で実装 | [index-c.html](https://jigintern.github.io/summer-2026-assignment/index-c.html) | [index-c.md](./index-c.md) |

各資料に、課題の仕様・提出方法・実装手順(チュートリアル)をまとめています。まずは応募コースの資料を最後まで読んだ上で、課題に取り組んでください。

## サンプルコード

資料のチュートリアル部分で使用するサンプル実装を同梱しています。

- [`sample/`](./sample) … Webコース用。Deno で HTTP サーバーを立てて、しりとりの API とフロントエンドを返すところまでの雛形
- [`sample-c/`](./sample-c) … SABERAコース用。C言語で書いた最小構成のしりとりプログラム

## 課題の提出

ソースコードと README を掲載した GitHub リポジトリのリンクを、以下の Google フォームから提出してください。

[課題提出用 Google フォーム](https://forms.gle/v2rkvJUsamCrWWvS7)

README に含めていただきたい項目(動作確認URL/スクリーンショット、実装した機能の説明、参考にしたサイト、AIの活用方法など)はコースによって異なるため、必ず各コースの資料を参照してください。

## このリポジトリの構成

```
.
├── index.md         # Webコース用 課題資料(Markdown)
├── index-c.md       # SABERAコース用 課題資料(Markdown)
├── imgs/            # 資料内で使用する画像
├── sample/          # Webコース用 サンプル実装(Deno)
├── sample-c/        # SABERAコース用 サンプル実装(C)
└── .github/workflows/gh-pages.yaml  # index*.md を HTML 化して GitHub Pages へ公開
```

`main` ブランチへの push をトリガーに、`index.md` / `index-c.md` が HTML に変換され GitHub Pages にデプロイされます。
