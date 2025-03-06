#!/bin/bash

# Get the current wallpaper from swww
WALLPAPER=$(swww query | grep 'Image:' | awk '{print $2}')

# Check if a wallpaper is found
if [ -n "$WALLPAPER" ]; then
    wal -i "$WALLPAPER"
    xrdb -merge ~/.cache/wal/colors.Xresources
else
    echo "No wallpaper found through swww."
fi

