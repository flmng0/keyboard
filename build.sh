#!/usr/bin/bash

dir="$HOME/qmk_firmware"

podman run --rm \
  --privileged \
	-w /qmk_firmware \
	-v "$dir":/qmk_firmware \
	ghcr.io/qmk/qmk_cli \
	qmk compile -c "users/flmng0/keymaps/combo.json"
