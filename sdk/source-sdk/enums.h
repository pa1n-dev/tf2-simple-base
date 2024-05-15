#pragma once

enum struct tf_class_id
{
	c_tf_wearable_razorback = 341,
	c_tf_wearable_demo_shield = 338,
	c_tf_wearable_levelable_item = 340,
	c_tf_wearable_campaign_item = 337,
	c_tf_base_rocket = 185,
	c_tf_weapon_base_merasmus_grenade = 325,
	c_tf_weapon_base_melee = 324,
	c_tf_weapon_base_gun = 323,
	c_tf_weapon_base_grenade_proj = 322,
	c_tf_weapon_base = 321,
	c_tf_wearable_robot_arm = 342,
	c_tf_robot_arm = 287,
	c_tf_wrench = 344,
	c_tf_projectile_throwable_bread_monster = 279,
	c_tf_projectile_throwable_brick = 280,
	c_tf_projectile_throwable_repel = 281,
	c_tf_projectile_throwable = 278,
	c_tf_throwable = 319,
	c_tf_syringe_gun = 315,
	c_tf_katana = 225,
	c_tf_sword = 314,
	c_sniper_dot = 118,
	c_tf_sniper_rifle_classic = 308,
	c_tf_sniper_rifle_decap = 309,
	c_tf_sniper_rifle = 307,
	c_tf_charged_smg = 197,
	c_tf_smg = 306,
	c_tf_slap = 305,
	c_tf_shovel = 304,
	c_tf_shotgun_building_rescue = 303,
	c_tf_pep_brawler_blaster = 241,
	c_tf_soda_popper = 310,
	c_tf_shotgun_revenge = 301,
	c_tf_scatter_gun = 297,
	c_tf_shotgun_pyro = 300,
	c_tf_shotgun_hwg = 299,
	c_tf_shotgun_soldier = 302,
	c_tf_shotgun = 298,
	c_tf_rocket_pack = 296,
	c_tf_crossbow = 201,
	c_tf_rocket_launcher_mortar = 295,
	c_tf_rocket_launcher_air_strike = 293,
	c_tf_rocket_launcher_direct_hit = 294,
	c_tf_rocket_launcher = 292,
	c_tf_revolver = 286,
	c_tf_drg_pomson = 202,
	c_tf_raygun = 284,
	c_tf_pistol_scout_secondary = 246,
	c_tf_pistol_scout_primary = 245,
	c_tf_pistol_scout = 244,
	c_tf_pistol = 243,
	c_tf_pipebomb_launcher = 242,
	c_tf_weapon_pda_spy = 332,
	c_tf_weapon_pda_engineer_destroy = 331,
	c_tf_weapon_pda_engineer_build = 330,
	c_tf_weapon_pda_expansion_teleporter = 334,
	c_tf_weapon_pda_expansion_dispenser = 333,
	c_tf_weapon_pda = 329,
	c_tf_particle_cannon = 239,
	c_tf_parachute_secondary = 238,
	c_tf_parachute_primary = 237,
	c_tf_parachute = 236,
	c_tf_minigun = 234,
	c_tf_medigun_shield = 231,
	c_weapon_medigun = 352,
	c_tf_projectile_mechanical_arm_orb = 263,
	c_tf_mechanical_arm = 230,
	c_tf_lunch_box_drink = 229,
	c_tf_lunch_box = 228,
	c_laser_dot = 78,
	c_tf_laser_pointer = 227,
	c_tf_knife = 226,
	c_tf_gas_manager = 212,
	c_tf_projectile_jar_gas = 261,
	c_tf_jar_gas = 223,
	c_tf_projectile_cleaver = 254,
	c_tf_projectile_jar_milk = 262,
	c_tf_projectile_jar = 260,
	c_tf_cleaver = 198,
	c_tf_jar_milk = 224,
	c_tf_jar = 222,
	c_tf_weapon_invis = 328,
	c_tf_cannon = 196,
	c_tf_grenade_launcher = 216,
	c_tf_grenade_pipebomb_projectile = 217,
	c_tf_grappling_hook = 215,
	c_tf_flare_gun_revenge = 210,
	c_tf_flare_gun = 209,
	c_tf_flame_rocket = 207,
	c_tf_flame_thrower = 208,
	c_tf_fists = 205,
	c_tf_fire_axe = 204,
	c_tf_weapon_flame_ball = 327,
	c_tf_compound_bow = 200,
	c_tf_club = 199,
	c_tf_buff_item = 195,
	c_tf_stick_bomb = 312,
	c_tf_breakable_sign = 194,
	c_tf_bottle = 192,
	c_tf_breakable_melee = 193,
	c_tf_bonesaw = 190,
	c_tf_ball_ornament = 182,
	c_tf_stun_ball = 313,
	c_tf_bat_giftwrap = 188,
	c_tf_bat_wood = 189,
	c_tf_bat_fish = 187,
	c_tf_bat = 186,
	c_tf_projectile_energy_ring = 256,
	c_tf_dropped_weapon = 203,
	c_tf_weapon_sapper = 335,
	ctf_weapon_builder = 326,
	c_tf_weapon_builder = 0,
	c_tf_projectile_rocket = 264,
	c_tf_projectile_flare = 257,
	c_tf_projectile_energy_ball = 255,
	c_tf_projectile_grappling_hook = 258,
	c_tf_projectile_healing_bolt = 259,
	c_tf_projectile_arrow = 252,
	c_mann_vs_machine_stats = 80,
	c_tf_tank_boss = 316,
	c_tf_base_boss = 183,
	c_boss_alpha = 0,
	next_bot_combat_character = 357,
	c_tf_projectile_spell_kart_bats = 268,
	c_tf_projectile_spell_kart_orb = 269,
	c_tf_hell_zap = 220,
	c_tf_projectile_spell_lightning_orb = 270,
	c_tf_projectile_spell_transpose_teleport = 277,
	c_tf_projectile_spell_meteor_shower = 271,
	c_tf_projectile_spell_spawn_boss = 274,
	c_tf_projectile_spell_mirv = 272,
	c_tf_projectile_spell_pumpkin = 273,
	c_tf_projectile_spell_spawn_horde = 275,
	c_tf_projectile_spell_spawn_zombie = 276,
	c_tf_projectile_spell_bats = 266,
	c_tf_projectile_spell_fireball = 267,
	c_tf_spell_book = 311,
	c_hightower_teleport_vortex = 74,
	c_teleport_vortex = 160,
	c_zombie = 354,
	c_merasmus_dancer = 83,
	c_merasmus = 82,
	c_headless_hatman = 73,
	c_eyeball_boss = 48,
	c_tf_bot_hint_engineer_nest = 191,
	c_bot_npc_minion = 0,
	c_bot_npc = 0,
	c_passtime_gun = 94,
	c_tf_view_model = 320,
	c_robot_dispenser = 112,
	c_tf_robot_destruction_robot = 288,
	c_tf_revive_marker = 285,
	c_tf_pumpkin_bomb = 282,
	c_tf_projectile_ball_of_fire = 253,
	c_tf_base_projectile = 184,
	c_tf_point_manager = 250,
	c_base_object_upgrade = 11,
	c_tf_robot_destruction_logic = 291,
	c_tf_robot_destruction_robot_group = 289,
	c_tf_robot_destruction_robot_spawn = 290,
	c_tf_player_destruction_logic = 248,
	c_player_destruction_dispenser = 101,
	c_tf_minigame_logic = 233,
	c_tf_halloween_minigame_falling_platforms = 219,
	c_tf_halloween_minigame = 218,
	c_tf_mini_game = 232,
	c_tf_powerup_bottle = 251,
	c_tf_item = 221,
	c_halloween_soul_pack = 71,
	c_tf_generic_bomb = 213,
	c_bonus_round_logic = 23,
	c_tf_game_rules_proxy = 211,
	c_te_tf_particle_effect = 179,
	c_te_tf_explosion = 178,
	c_te_tf_blood = 177,
	c_tf_flame_manager = 206,
	c_halloween_gift_pickup = 69,
	c_bonus_duck_pickup = 21,
	c_halloween_pickup = 70,
	c_capture_flag_return_icon = 27,
	c_capture_flag = 26,
	c_bonus_pack = 22,
	c_tf_team = 318,
	c_tf_taunt_prop = 317,
	c_tf_player_resource = 249,
	c_tf_player = 247,
	c_tf_ragdoll = 283,
	c_te_player_anim_event = 165,
	c_tf_passtime_logic = 240,
	c_passtime_ball = 93,
	c_tf_objective_resource = 235,
	c_tf_glow = 214,
	c_te_fire_bullets = 152,
	c_tf_buff_banner = 0,
	c_tf_ammo_pack = 181,
	c_object_teleporter = 89,
	c_object_sentrygun = 88,
	c_tf_projectile_sentry_rocket = 265,
	c_object_sapper = 87,
	c_object_cart_dispenser = 85,
	c_object_dispenser = 86,
	c_monster_resource = 84,
	c_func_respawn_room_visualizer = 64,
	c_func_respawn_room = 63,
	c_func_passtime_goal = 61,
	c_func_force_field = 57,
	c_capture_zone = 28,
	c_currency_pack = 31,
	c_base_object = 10,
	c_test_traceline = 176,
	c_te_world_decal = 180,
	c_te_sprite_spray = 174,
	c_te_sprite = 173,
	c_te_sparks = 172,
	c_te_smoke = 171,
	c_te_show_line = 169,
	c_te_projected_decal = 167,
	c_te_player_decal = 166,
	c_te_physics_prop = 164,
	c_te_particle_system = 163,
	c_te_muzzle_flash = 162,
	c_te_large_funnel = 159,
	c_te_kill_player_attachments = 158,
	c_te_impact = 157,
	c_te_glow_sprite = 156,
	c_te_shatter_surface = 168,
	c_te_footprint_decal = 154,
	c_te_fizz = 153,
	c_te_explosion = 151,
	c_te_energy_splash = 150,
	c_te_effect_dispatch = 149,
	c_te_dynamic_light = 148,
	c_te_decal = 146,
	c_te_client_projectile = 145,
	c_te_bubble_trail = 144,
	c_te_bubbles = 143,
	c_te_b_s_p_decal = 142,
	c_te_break_model = 141,
	c_te_blood_stream = 140,
	c_te_blood_sprite = 139,
	c_te_beam_spline = 138,
	c_te_beam_ring_point = 137,
	c_te_beam_ring = 136,
	c_te_beam_points = 135,
	c_te_beam_laser = 134,
	c_te_beam_follow = 133,
	c_te_beam_ents = 132,
	c_te_beam_ent_point = 131,
	c_te_base_beam = 130,
	c_te_armor_ricochet = 129,
	c_te_metal_sparks = 161,
	c_steam_jet = 123,
	c_smoke_stack = 117,
	dust_trail = 355,
	c_fire_trail = 50,
	spore_trail = 362,
	spore_explosion = 361,
	rocket_trail = 359,
	smoke_trail = 360,
	c_prop_vehicle_driveable = 108,
	particle_smoke_grenade = 358,
	c_particle_fire = 90,
	movie_explosion = 356,
	c_te_gauss_explosion = 155,
	c_env_quadratic_beam = 43,
	c_embers = 36,
	c_env_wind = 47,
	c_precipitation = 107,
	c_base_temp_entity = 17,
	c_weapon_ifm_steady_cam = 351,
	c_weapon_ifm_base_camera = 350,
	c_weapon_ifm_base = 349,
	c_tf_wearable_vm_ = 343,
	c_tf_wearable = 336,
	c_tf_wearable_item = 339,
	c_econ_wearable = 35,
	c_base_attributable_item = 3,
	c_econ_entity = 34,
	c_handle_test = 72,
	c_teamplay_round_based_rules_proxy = 126,
	c_team_round_timer = 127,
	c_sprite_trail = 122,
	c_sprite_oriented = 121,
	c_sprite = 120,
	c_ragdoll_prop_attached = 111,
	c_ragdoll_prop = 110,
	c_pose_controller = 106,
	c_game_rules_proxy = 68,
	c_info_ladder_dismount = 75,
	c_func_ladder = 58,
	c_env_detail_controller = 40,
	c_world = 353,
	c_water_lod_control = 348,
	c_water_bullet = 347,
	c_vote_controller = 346,
	c_v_gui_screen = 345,
	c_prop_jeep = 0,
	c_prop_vehicle_choreo_generic = 0,
	c_test_proxy_toggle_networkable = 175,
	c_tesla = 170,
	c_team_train_watcher = 128,
	c_base_team_objective_resource = 16,
	c_team = 125,
	c_sun = 124,
	c_particle_performance_monitor = 91,
	c_spotlight_end = 119,
	c_slideshow_display = 116,
	c_shadow_control = 115,
	c_scene_entity = 114,
	c_rope_keyframe = 113,
	c_ragdoll_manager = 109,
	c_physics_prop_multiplayer = 98,
	c_phys_box_multiplayer = 96,
	c_base_prop_door = 15,
	c_dynamic_prop = 33,
	c_point_world_text = 105,
	c_point_commentary_node = 104,
	c_point_camera = 103,
	c_player_resource = 102,
	c_plasma = 100,
	c_phys_magnet = 99,
	c_physics_prop = 97,
	c_phys_box = 95,
	c_particle_system = 92,
	c_material_modify_control = 81,
	c_light_glow = 79,
	c_info_overlay_accessor = 77,
	c_func_track_train = 67,
	c_func_smoke_volume = 66,
	c_func_rotating = 65,
	c_func_reflective_glass = 62,
	c_func_occluder = 60,
	c_func_monitor = 59,
	c_func_lod = 54,
	c_te_dust = 147,
	c_func_dust = 53,
	c_func_conveyor = 56,
	c_breakable_surface = 25,
	c_func_area_portal_window = 55,
	c_fish = 51,
	c_entity_flame = 38,
	c_fire_smoke = 49,
	c_env_tonemap_controller = 46,
	c_env_screen_effect = 44,
	c_env_screen_overlay = 45,
	c_env_projected_texture = 42,
	c_env_particle_script = 41,
	c_fog_controller = 52,
	c_entity_particle_trail = 39,
	c_entity_dissolve = 37,
	c_dynamic_light = 32,
	c_color_correction_volume = 30,
	c_color_correction = 29,
	c_breakable_prop = 24,
	c_base_player = 13,
	c_base_flex = 8,
	c_base_entity = 7,
	c_base_door = 6,
	c_base_combat_character = 4,
	c_base_animating_overlay = 2,
	c_bone_follower = 20,
	c_base_animating = 1,
	c_info_lighting_relative = 76,
	c_ai_base_npc = 0,
	c_beam = 19,
	c_base_view_model = 18,
	c_base_projectile = 14,
	c_base_particle_entity = 12,
	c_base_grenade = 9,
	c_base_combat_weapon = 5,
};