#!/bin/bash

# Path to your wallpapers folder
WALLPAPER_DIR="$HOME/Pictures"

# Pick a random wallpaper
WALLPAPER=$(find "$WALLPAPER_DIR" -type f \( -iname '*.jpg' -o -iname '*.png' \) | shuf -n 1)

# Set wallpaper and apply pywal
swww img "$WALLPAPER" --transition-type grow --transition-duration 1
wal -i "$WALLPAPER"

# Reload Waybar or any other app that uses the colors


