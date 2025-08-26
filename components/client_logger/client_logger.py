import esphome.codegen as cg
import esphome.config_validation as cv

client_logger_ns = cg.esphome_ns.namespace('client_logger')
ClientLogger = client_logger_ns.class_('ClientLogger', cg.Component)

CONFIG_SCHEMA = cv.Schema({})