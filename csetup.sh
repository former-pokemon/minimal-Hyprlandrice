hyprctl dispatch exec "zen-browser"
sleep 1
hyprctl dispatch movetoworkspace 2
sleep 1
hyprctl dispatch workspace 1

 Switch to workspace 1
hyprctl dispatch workspace 1

# Launch the top terminal
kitty --title "Main Terminal" --directory ~/c &
sleep 1

# Force Kitty to tile if floating
hyprctl dispatch togglefloating

# Launch the bottom terminal
kitty --title "Small Terminal" --directory ~/c &
sleep 1

# Force the second terminal to tile
hyprctl dispatch togglefloating

# Manually split the layout
hyprctl dispatch splitratio 0.8
hyprctl dispatch movefocus d
exit
exit
exit
