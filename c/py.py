
{
    "layer": "top",
    "position": "top",
    "height": 40,
    "modules-left": [
        "hyprland/workspaces",
        "scratchpad",
        "custom/caffeine"
    ],
    "modules-center": [
        "clock"
    ],
    "modules-right": [
        "cpu",
        "pulseaudio",
        "backlight"
    ],
    "custom/caffeine": {
        "format": "  {icon}",
        "format-icons": ["OFF", "ON"],
        "on-click": "pkill -USR1 hypridle || hypridle &",
        "tooltip": false
    },
    "cpu": {
        "interval": 2,
        "format": "  {usage}%",
        "on-click": "kitty btop"
    },
    "clock": {
        "interval": 1,
        "format": "  {:%H:%M:%S}"
    },
    "pulseaudio": {
        "format": "  {volume}%",
        "format-muted": "  Muted",
        "on-click": "pavucontrol"
    },
    "backlight": {
        "format": "  {percent}%"
    }
}

