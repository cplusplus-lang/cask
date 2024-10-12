#!/usr/bin/env python3

MAPPING = {
    "index.html": "https://doc.cplusplus-lang.com/cask/",
}

TEMPLATE = """\
<html>
<head>
<meta http-equiv="refresh" content="0; url={mapped}" />
<script>
window.location.replace("{mapped}" + window.location.hash);
</script>
<title>Page Moved</title>
</head>
<body>
This page has moved. Click <a href="{mapped}">here</a> to go to the new page.
</body>
</html>
"""

def main():
    for name in sorted(MAPPING):
        with open(name, 'w') as f:
            f.write(TEMPLATE.format(name=name, mapped=MAPPING[name]))

    # WARN: The CNAME file is for GitHub to redirect requests to the custom domain.
    # Missing this may entail security hazard and domain takeover.
    # See <https://docs.github.com/en/pages/configuring-a-custom-domain-for-your-github-pages-site/managing-a-custom-domain-for-your-github-pages-site#securing-your-custom-domain>
    with open('CNAME', 'w') as f:
        f.write('doc.cplusplus-lang.com')

if __name__ == '__main__':
    main()