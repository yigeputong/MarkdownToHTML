
# 项目介绍

一个用于将一个 Markdown 文件转换为一段 HTML 文本的软件。

## 使用方法

> mth + <一个 Markdown 文件的路径> + <选项>

- 无选项：将选中的 Markdown 文件转换为一段包裹在一个&lt;main&gt;标签里的 HTML 文本。

- -a：

```html
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<title>Document</title>
</head>
<body>
<main>
<!--将选中的 Markdown 文件转换为一段包裹在这里的 HTML 文本。-->
</main>
</body>
</html>
```
