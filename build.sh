#!/usr/bin/bash

dir="$HOME/qmk_firmware"
user="flmng0"

podman run --rm \
  --privileged \
	-w /qmk_firmware \
	-v "$dir":/qmk_firmware \
  -v "$PWD":"/qmk_firmware/users/$user" \
	ghcr.io/qmk/qmk_cli \
	qmk compile -c "users/$user/keymaps/combo.json"
