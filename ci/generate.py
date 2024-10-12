#!/usr/bin/env python3

def main():
    # WARN: The CNAME file is for GitHub to redirect requests to the custom domain.
    # Missing this may entail security hazard and domain takeover.
    # See <https://docs.github.com/en/pages/configuring-a-custom-domain-for-your-github-pages-site/managing-a-custom-domain-for-your-github-pages-site#securing-your-custom-domain>
    with open('CNAME', 'w') as f:
        f.write('doc.cplusplus-lang.com')

if __name__ == '__main__':
    main()