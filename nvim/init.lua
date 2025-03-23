-- Basic settings
vim.opt.number = true
vim.opt.relativenumber = true
vim.opt.tabstop = 4
vim.opt.shiftwidth = 4
vim.opt.expandtab = true
vim.opt.termguicolors = true

-- Load Lazy.nvim
local lazypath = vim.fn.stdpath("data") .. "/lazy/lazy.nvim"
if not vim.loop.fs_stat(lazypath) then
    vim.fn.system({
        "git", "clone", "--filter=blob:none",
        "https://github.com/folke/lazy.nvim.git", lazypath,
    })
end
vim.opt.rtp:prepend(lazypath)

-- Plugin setup
require("lazy").setup({
    "preservim/nerdtree",
    "nvim-lualine/lualine.nvim",
    "vim-airline/vim-airline",
    "junegunn/fzf.vim",
    {
        "catppuccin/nvim",
        name = "catppuccin"
    },
    {
        "hrsh7th/nvim-cmp",
        dependencies = {
            "hrsh7th/cmp-nvim-lsp",
            "hrsh7th/cmp-buffer",
            "hrsh7th/cmp-path",
            "hrsh7th/cmp-cmdline",
            "L3MON4D3/LuaSnip",
            "saadparwaiz1/cmp_luasnip"
        }
    },
    {
    "nvim-telescope/telescope.nvim",
    dependencies = { "nvim-lua/plenary.nvim" }
}
    })

local cmp = require("cmp")

cmp.setup({
    mapping = cmp.mapping.preset.insert({
        ["<Tab>"] = cmp.mapping.select_next_item(), -- Tab to navigate
        ["<S-Tab>"] = cmp.mapping.select_prev_item(), -- Shift+Tab to go back
        ["<CR>"] = cmp.mapping.confirm({ select = true }), -- Enter to confirm
    }),
    sources = cmp.config.sources({
        { name = "nvim_lsp" },
        { name = "buffer" },
        { name = "path" },
        { name = "luasnip" },
    }),
})


-- Catppuccin theme config
require("catppuccin").setup({
    flavour = "mocha",
    transparent_background = true
})
vim.cmd.colorscheme "catppuccin-mocha"

-- Keybindings for C development
vim.api.nvim_set_keymap('n', '<F5>', ':w<CR>:!gcc % -o %:r && ./%:r<CR>', { noremap = true, silent = true })
vim.api.nvim_set_keymap('n', '<F9>', ':!gdb ./%:r<CR>', { noremap = true, silent = true })

-- Statusline setup
require("lualine").setup({
    options = {globalstatus = true }})

-- NERDTree keybinding
vim.api.nvim_set_keymap('n', '<C-n>', ':NERDTreeToggle<CR>', { noremap = true, silent = true })

-- Clipboard keybindings
vim.api.nvim_set_keymap('v', '<C-c>', '"+y', { noremap = true, silent = true })
vim.api.nvim_set_keymap('n', '<C-v>', '"+p', { noremap = true, silent = true })

-- Keybinding to open another file
vim.api.nvim_set_keymap('n', '<C-o>', ':e ', { noremap = true, silent = false })
vim.opt.clipboard = "unnamedplus"

