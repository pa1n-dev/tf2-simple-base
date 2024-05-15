HRESULT APIENTRY hooks::handles::present(IDirect3DDevice9* device, CONST RECT* src, CONST RECT* dest, HWND wnd_override, CONST RGNDATA* dirty_region)
{
	render.setup(device);
	render.setup_states(device);
	render.start();

	menu.run();

	render.end();
	render.backup_states(device);

	if (ImGui::IsKeyPressed(ImGuiKey_Insert, false))
		menu.opened = !menu.opened;

	return originals::present(device, src, dest, wnd_override, dirty_region);
}